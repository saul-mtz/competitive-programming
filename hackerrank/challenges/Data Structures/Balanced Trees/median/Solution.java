import java.util.Scanner;

/**
 * Self Balancing Tree
 *
 * @link   https://www.hackerrank.com/challenges/median
 * @author saul.martinez
 */
class Solution {

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Node tree = new Node();

        for (int i = 0; i < n; i ++) {
            char operation = in.next().charAt(0);
            int value = in.nextInt();

            if ('a' == operation) {
                tree.insert(value);
            }
        }

        System.out.println(tree);
    }
}

class Node {
    int val;
    int height;
    int balanceFactor;
    Node left;
    Node right;

    /**
     * Add a new element to the AVL tree
     *
     * @param val
     * @return
     */
    public Node insert(int val) {
        return insert(this, val);
    }

    /**
     * Add a new element to the AVL tree
     *
     * @param val
     * @return
     */
    private Node insert(Node n, int val) {
        // populate the root element
        if (0 == n.val && null == n.left && null == n.right) {
            n.val = val;

        // insert the new value in the right subtree
        } else if (val > n.val) {
            if (null == n.right) {
                n.right = createNode(val);
            } else {
                insert(n.right, val);
            }

        // insert the new value in the left subtree
        } else {
            if (null == n.left) {
                n.left = createNode(val);
            } else {
                insert(n.left, val);
            }
        }

        // update the balance factor
        n.balanceFactor = (null == n.left ? -1 : n.left.height) - (null == n.right ? -1 : n.right.height);

        // do rotations if needed
        if (-2 == n.balanceFactor || 2 == n.balanceFactor) {
            balance(n);
        }

        n.updateHeight();
        return n;
    }

    /**
     * Create a new node, default height is zero
     *
     * @param val
     * @return
     */
    public Node createNode(int val) {
        Node n = new Node();
        n.val = val;
        return n;
    }

    /**
     * Recalc the height for each ancestor
     */
    public void updateHeight() {
        int hLeft  = null == this.left ? -1 : this.left.height;
        int hRight = null == this.right ? -1 : this.right.height;
        this.height = Math.max(hLeft, hRight) + 1;
    }

    static void balance(Node n) {
        if (-2 == n.balanceFactor) {
            if (-1 == n.right.balanceFactor) {
                // right right case
                rotateLeft(n);
            } else {
                // right left base
                rotateRight(n.right);
                rotateLeft(n);
            }
        } else {
            if (-1 == n.left.balanceFactor) {
                // left right case
                rotateLeft(n.left);
                rotateRight(n);
            } else {
                // left left case
                rotateRight(n);
            }
        }
    }

    static void rotateLeft(Node n) {
        Node newNode = new Node();
        newNode.val = n.val;
        newNode.left = n.left;
        newNode.right = n.right.left;

        n.val = n.right.val;
        n.right = n.right.right;
        n.left = newNode;

        n.left.updateHeight();
    }

    static void rotateRight(Node n) {
        Node newNode = new Node();
        newNode.val = n.val;
        newNode.right = n.right;
        newNode.left = n.left.right;

        n.val = n.left.val;
        n.left = n.left.left;
        n.right= newNode;

        n.right.updateHeight();
    }

    public String toString() {
        return toString(this);
    }

    /**
     * Create a string representation of the tee traversed in-order
     *
     * @param n
     * @return
     */
    public String toString(Node n) {
        String s = "";
        if (null != n.left) {
            s += toString(n.left);
        }
        s += n.val + "(H=" + n.height + ",BF=" + n.balanceFactor + ") ";
        if (null != n.right) {
            s += toString(n.right);
        }

        return s;
    }

}