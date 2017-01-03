import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
/*
import static junit.framework.Assert.assertTrue;
import static junit.framework.TestCase.assertEquals;
*/
public class Solution {

    static class TreeNode {

        // internal index for the node
        private int index;
        public int indexMin;
        public int indexMax;

        // node metadata
        public boolean isLeaf;      // true if this node is a leaf (has no children)
        public boolean isLeft;      // true if this node is a left child of another node
        public boolean isRoot;      // true if this node is the root of a tree
        private int height;         // height of the node as subtree

        // data to be saved
        Integer data;

        // node relationships
        private TreeNode parent;
        private TreeNode left;
        private TreeNode right;

        TreeNode(Integer value) {
            data   = value;
            isLeaf = true;
            height = 0;
        }

        public TreeNode getParent() {
            return parent;
        }

        public void setParent(TreeNode parent) {
            this.parent = parent;
            isRoot = null == parent;
            this.isLeft = !isRoot && null != parent.getLeft() && parent.getLeft().equals(this);
        }

        public TreeNode getLeft() {
            return left;
        }

        public void setLeft(TreeNode left) {
            if (null != getLeft() && null == left) {
                getLeft().setParent(null);
            }

            int index = null == getLeft() ? -1 : getLeft().getIndex();
            this.left = left;

            int updatedHeight;

            if (null != left) {
                left.setParent(this);
                isLeaf = false;
                updatedHeight = Math.max(null == right ? -1 : right.getHeight(), left.getHeight()) + 1;
            } else if (null == right) {
                isLeaf = true;
                updatedHeight = 0;
            } else {
                updatedHeight = right.getHeight() + 1;
            }

            if (updatedHeight != height) {
                height = updatedHeight;
                if (null != parent) {
                    parent.updateHeight();
                }
            }
        }

        public TreeNode getRight() {
            return right;
        }

        public void setRight(TreeNode right) {
            if (null != getRight() && null == right) {
                getRight().setParent(null);
            }

            int index = null == getRight() ? -1 : getRight().getIndex();
            this.right = right;
            int updatedHeight;

            if (null != right) {
                right.setParent(this);
                isLeaf = false;
                updatedHeight = Math.max(null == left ? -1 : left.getHeight(), right.getHeight()) + 1;
            } else if (null == left) {
                isLeaf = true;
                updatedHeight = 0;
            } else {
                updatedHeight = left.getHeight() + 1;
            }

            if (updatedHeight != height) {
                height = updatedHeight;
                if (null != parent) {
                    parent.updateHeight();
                }
            }
        }

        public int getHeight() {
            return height;
        }

        public Integer getValue() {
            return data;
        }

        public int getIndex() {
            return index;
        }

        public int getSize() {
            return 1 + (null == left ? 0 : left.inOrder().size()) + (null == right ? 0 : right.inOrder().size());
        }

        public boolean equals(TreeNode node) {
            return getValue().equals(node.getValue()) && getIndex() == node.getIndex();
        }

        public String toString() {
            return inOrder().toString();
        }

        private void updateHeight() {
            int heightLeft  = null == left  ? -1 : left.getHeight();
            int heightRight = null == right ? -1 : right.getHeight();

            int updatedHeight = Math.max(heightLeft, heightRight) + 1;

            if (updatedHeight != height) {
                height = updatedHeight;
                if (null != parent) {
                    parent.updateHeight();
                }
            }
        }

        public List<Integer> inOrder() {

            List<Integer> values = new ArrayList<>();

            if (null != left) {
                values.addAll(left.inOrder());
            }

            values.add(data);
            if (null != right) {
                values.addAll(right.inOrder());
            }

            return values;
        }

        public void reindex(int offset) {
            indexMin = offset;
            if (null != left) {
                left.reindex(offset);
                offset += left.getSize();
            }

            index = offset;

            if (null != right) {
                right.reindex(offset + 1);
                offset += right.getSize();
            }
            indexMax = offset;
        }

        public TreeNode findMin() {
            TreeNode minTreeNode = this;
            while (null != minTreeNode.getLeft()) {
                minTreeNode = minTreeNode.getLeft();
            }
            return minTreeNode;
        }

        public TreeNode findMax() {
            TreeNode maxTreeNode = this;
            while (null != maxTreeNode.getRight()) {
                maxTreeNode = maxTreeNode.getRight();
            }
            return maxTreeNode;
        }

        public TreeNode remove(boolean removeChildren) {
            TreeNode parent = this.getParent();
            TreeNode toReplace = null;

            // three possible cases according to: https://en.wikipedia.org/wiki/Binary_search_tree#Deletion
            if (null == this.getLeft() && null == this.getRight()) {
                // case 1: node with no children

                if (!isRoot) {
                    if (isLeft) {
                        parent.setLeft(null);
                    } else {
                        parent.setRight(null);
                    }
                } else {
                    return null;
                }
            } else if ((null != this.getLeft() && null == this.getRight()) || (null == this.getLeft()  && null != this.getRight())) {

                if (removeChildren) {
                    if (null != getParent()) {
                        if (isLeft) {
                            getParent().setLeft(null);
                        } else {
                            getParent().setRight(null);
                        }
                    }
                } else {
                    // case 2: Nodes with only one child
                    if (null != this.getLeft()) {
                        TreeNode left = this.getLeft();
                        this.setLeft(null);
                        if (!isRoot) {
                            if (isLeft) {
                                parent.setLeft(left);
                            } else {
                                parent.setRight(left);
                            }
                        } else {
                            toReplace = left;
                        }
                    } else {
                        TreeNode right = this.getRight();
                        this.setRight(null);

                        if (!isRoot) {
                            if (isLeft) {
                                parent.setLeft(right);
                            } else {
                                parent.setRight(right);
                            }
                        } else {
                            toReplace = right;
                        }
                    }
                }
                this.setParent(null);
            } else {
                if (removeChildren) {
                    if (null != getParent()) {
                        if (isLeft) {
                            getParent().setLeft(null);
                        } else {
                            getParent().setRight(null);
                        }
                    }
                } else {
                    // case 3: Nodes with two children
                    toReplace = this.getRight().findMin();
                    swapWith(toReplace);
                    this.remove(removeChildren);
                }
            }

            if (null != parent) {
                parent.indexMin = parent.findMin().getIndex();
                parent.indexMax = parent.findMax().getIndex();
            }
            return null != toReplace && toReplace.isRoot ? toReplace : this;
        }

        private void swapWith(TreeNode node) {
            // there is nothing to do
            if (null == node || this.equals(node)) {
                return;
            }

            TreeNode thisParent = getParent();
            TreeNode nodeParent = node.getParent();

            boolean isThisLeft = isLeft;
            boolean isNodeLeft = node.isLeft;

            TreeNode thisLeft = this.getLeft();
            TreeNode thisRight = this.getRight();

            TreeNode nodeLeft = node.getLeft();
            TreeNode nodeRight = node.getRight();

            if (null != nodeParent && nodeParent.equals(this)) {
                this.setLeft(nodeLeft);
                this.setRight(nodeRight);

                if (isNodeLeft) {
                    node.setLeft(this);
                    node.setRight(thisRight);
                } else {
                    node.setRight(this);
                    node.setLeft(thisLeft);
                }

                if (null != thisParent) {
                    if (isThisLeft) {
                        thisParent.setLeft(node);
                    } else {
                        thisParent.setRight(node);
                    }
                } else {
                    node.setParent(null);
                }

                return;
            }

            if (null != thisParent) {
                if (isThisLeft) {
                    thisParent.setLeft(null);
                } else {
                    thisParent.setRight(null);
                }
            }

            if (null != nodeParent) {
                if (isNodeLeft) {
                    nodeParent.setLeft(null);
                } else {
                    nodeParent.setRight(null);
                }
            }

            this.setLeft(nodeLeft);
            this.setRight(nodeRight);
            node.setLeft(thisLeft);
            node.setRight(thisRight);

            if (null != thisParent) {
                if (isThisLeft) {
                    thisParent.setLeft(node);
                } else {
                    thisParent.setRight(node);
                }
            }

            if (null != nodeParent) {
                if (isNodeLeft) {
                    nodeParent.setLeft(this);
                } else {
                    nodeParent.setRight(this);
                }
            }
        }

        public int getBalanceFactor() {
            int hLeft = null == getLeft() ? -1 : getLeft().getHeight();
            int hRight = null == getRight() ? -1 : getRight().getHeight();
            return hLeft - hRight;
        }
    }

    static class AvlTree {

        public TreeNode root;

        public TreeNode add(Integer value) {
            TreeNode node;
            if (null == root) {
                node = new TreeNode(value);
                root = node;
                root.setParent(null);
            } else {
                node = insert(root, root, true, value);
            }

            balance(node);
            return node;
        }

        public TreeNode removeNode(TreeNode node, boolean removeChildren) {
            if (node.isRoot) {
                root = node.remove(removeChildren);
                return node;
            } else {
                return node.remove(removeChildren);
            }
        }

        public String toString() {
            return null == root ? "[]" : root.toString();
        }

        private TreeNode insert(TreeNode node, TreeNode parent, boolean isLeft, Integer value) {
            if (null == node) {
                node = new TreeNode(value);
                if (isLeft) {
                    parent.setLeft(node);
                } else {
                    parent.setRight(node);
                }
                return node;
            } else if (value < node.data) {
                return insert(node.getLeft(), node, true, value);
            } else {
                return insert(node.getRight(), node, false, value);
            }
        }

        public boolean isBalanced() {
            return null == root || root.getBalanceFactor() > -2 && root.getBalanceFactor() < 2;
        }

        public void balance(TreeNode node) {
            while (null != node) {
                // check the balance factor and do rotations if needed
                int balanceFactor = node.getBalanceFactor();
                if (balanceFactor < -1 || balanceFactor > 1) {
                    balance(node, balanceFactor);
                }

                node = node.getParent();
            }
        }

        private void balance(TreeNode n, int balanceFactor) {
            if (balanceFactor < -1) {
                if (n.getRight().getBalanceFactor() < 0) {
                    // right right case
                    rotateLeft(n);
                } else {
                    // right left case
                    rotateRight(n.getRight());
                    rotateLeft(n);
                }
            } else {
                if (n.getLeft().getBalanceFactor() < 0) {
                    // left right case
                    rotateLeft(n.getLeft());
                    rotateRight(n);
                } else {
                    // left left case
                    rotateRight(n);
                }
            }
        }

        /**
         * Left rotation taken from https://en.wikipedia.org/wiki/Tree_rotation#Illustration
         * @param node
         */
        private void rotateLeft(TreeNode node) {
            TreeNode pivot = node.getRight();
            TreeNode parent = node.getParent();
            boolean isLeft = node.isLeft;

            if (null == pivot.getLeft()) {
                node.setRight(null);
            } else {
                node.setRight(pivot.getLeft().remove(true));
            }
            pivot.setLeft(node);

            if (null == parent) {
                root = pivot;
                pivot.setParent(null);
            } else {
                if (isLeft) {
                    parent.setLeft(pivot);
                } else {
                    parent.setRight(pivot);
                }
            }

            if (null != parent) {
                parent.indexMin = parent.findMin().getIndex();
                parent.indexMax = parent.findMax().getIndex();
            }

            pivot.indexMin = pivot.findMin().getIndex();
            pivot.indexMax = pivot.findMax().getIndex();

            node.indexMin = node.findMin().getIndex();
            node.indexMax = node.findMax().getIndex();
        }

        /**
         * Right node rotation, taken from https://en.wikipedia.org/wiki/Tree_rotation#Illustration
         * @param node
         */
        private void rotateRight(TreeNode node) {
            TreeNode pivot = node.getLeft();
            TreeNode parent = node.getParent();
            boolean isLeft = node.isLeft;

            if (null == pivot.getRight()) {
                node.setLeft(null);
            } else {
                node.setLeft(pivot.getRight().remove(true));
            }
            pivot.setRight(node);

            if (null == parent) {
                root = pivot;
                pivot.setParent(null);
            } else {
                if (isLeft) {
                    parent.setLeft(pivot);
                } else {
                    parent.setRight(pivot);
                }
            }

            if (null != parent) {
                parent.indexMin = parent.findMin().getIndex();
                parent.indexMax = parent.findMax().getIndex();
            }

            pivot.indexMin = pivot.findMin().getIndex();
            pivot.indexMax = pivot.findMax().getIndex();

            node.indexMin = node.findMin().getIndex();
            node.indexMax = node.findMax().getIndex();
        }
    }

    public static void solve(int queryType, int i, int j) {
        TreeNode node = numbers.root;

        // biggest node that contains the index range
        TreeNode rangeNode = null;
        while (null != node && (node.indexMin <= i && j <= node.indexMax)) {
            rangeNode = node;
            if (i < node.getIndex()) {
                node = node.getLeft();
            } else {
                node = node.getRight();
            }
        }

        if (null != rangeNode) {
            if (2 == queryType && j < numbers.root.getSize()) {
                moveToBack(rangeNode, i, j, queryType);
                numbers.root.findMax().setRight(toMove.root);
                numbers.balance(numbers.root.findMax());
            } else if (1 == queryType && i > 1) {
                moveToFront(rangeNode, i, j, queryType);
                numbers.root.findMin().setLeft(toMove.root);
                numbers.balance(numbers.root.findMin());
            }
        }
    }

    private static void moveToFront(TreeNode node, int i, int j, int queryType) {

        if (node.indexMin >= i && node.indexMax <= j) {
            moveNode(numbers.removeNode(node, true), queryType);
        } else {
            TreeNode left = node.getLeft();
            TreeNode right = node.getRight();

            if (null != right && right.indexMin <= j) {
                moveToFront(right, i, j, queryType);
            }

            if (i <= node.getIndex() && node.getIndex() <= j) {
                moveNode(numbers.removeNode(node, false), queryType);
            }

            if (null != left && left.indexMax >= i) {
                moveToFront(left, i, j, queryType);
            }
        }
    }

    private static void moveToBack(TreeNode node, Integer i, Integer j, int queryType) {
        if (node.indexMin >= i && node.indexMax <= j) {
            moveNode(numbers.removeNode(node, true), queryType);
        } else {
            TreeNode left = node.getLeft();
            TreeNode right = node.getRight();

            if (null != left && left.indexMax >= i) {
                moveToBack(left, i, j, queryType);
            }

            if (i <= node.getIndex() && node.getIndex() <= j) {
                int rightSize = null == right ? 0 : right.getSize();
                moveNode(numbers.removeNode(node, false), queryType);
                if (null != right && right.getSize() < rightSize) {
                    right = right.getParent();
                    right.indexMin = right.findMin().indexMin;
                    right.indexMax = right.findMax().indexMax;
                }
            }

            if (null != right && right.indexMin <= j) {
                moveToBack(right, i, j, queryType);
            }
        }
    }

    private static void moveNode(TreeNode node, int queryType) {
        if (null == toMove.root) {
            toMove.root = node;
        } else {
            if (1 == queryType) {
                toMove.root.findMin().setLeft(node);
            } else {
                toMove.root.findMax().setRight(node);
            }
        }
    }

    private static AvlTree numbers;
    private static AvlTree toMove;

    /*
    public static void main(String args[]) {
        int treeLength = 512;
        initTree(treeLength);
        testType(2, treeLength);
        testType(1, treeLength);
    }

    private static void testType(int queryType, int treeLength) {
        for (int i = 1; i <= numbers.root.getSize(); i ++) {

            for (int j = 1; (j+i-1) <= numbers.root.getSize(); j ++) {
                ArrayList<Integer> test = new ArrayList<>();

                int from = i, to = i+j-1;

                if (1 == queryType) {
                    for (int k = i; k <= to; k++) {
                        test.add(k);
                    }
                }

                for (int k = 1; k < i; k ++) {
                    test.add(k);
                }

                for (int k = i+j; k <= numbers.root.getSize(); k ++) {
                    test.add(k);
                }

                if (2 == queryType) {
                    for (int k = i; k <= to; k++) {
                        test.add(k);
                    }
                }

                System.out.printf("qt=%d\t[%02d,%02d]\tlen=%02d\t%s\n", queryType, from, to, j, test);

                initTree(treeLength);
                toMove = new AvlTree();

                // queryType == 2 && 2 == from && 5 == to
                solve(queryType, from, to);
                //System.out.println(numbers);
                assertEquals(numbers.toString(), test.toString());
                assertTrue(numbers.isBalanced());
            }
        }
    }

    private static void initTree(int length) {
        numbers = new AvlTree();
        for (int i = 1; i < length; i ++) {
            numbers.add(i);
        }

        numbers.root.reindex(1);
    }*/

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        numbers = new AvlTree();
        TreeNode lastNode = null;
        while (n-- > 0) {
            TreeNode node = new TreeNode(in.nextInt());
            if(null == numbers.root) {
                numbers.root = node;
            } else {
                lastNode.setRight(node);
            }
            lastNode = node;
        }

        numbers.balance(lastNode);

        //System.out.println(m + " queries");
        while (m-- > 0) {
            numbers.root.reindex(1);
            toMove = new AvlTree();

            int type = in.nextInt(), i = in.nextInt(), j = in.nextInt();
            //solve(in.nextInt(), in.nextInt(), in.nextInt());
            solve(type, i, j);
            //System.out.printf("%d: %d %d %d\n", m, type, i, j);
        }

        StringBuilder sb = new StringBuilder();
        for (Integer number : numbers.root.inOrder()) {
            sb.append(number);
            sb.append(' ');
        }
        System.out.println(Math.abs(numbers.root.findMin().getValue()-numbers.root.findMax().getValue()));
        System.out.println(sb);
    }


}