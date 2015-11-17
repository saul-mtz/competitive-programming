import java.util.Scanner;

/**
 * Self Balancing Tree
 *
 * @link   https://www.hackerrank.com/challenges/self-balancing-tree
 * @author saul.martinez
 */
class Solution {

    static void printTree(Node node) {
        // traverse in-order
        printInOrder(node);
        System.out.println();
        printPreOrder(node);
        System.out.println();
    }

    static void printInOrder(Node n) {
        if (null != n.left) {
            printInOrder(n.left);
        }

        System.out.print(n.val + "(BF=" + balanceFactor(n) + ") ");

        if (null != n.right) {
            printInOrder(n.right);
        }
    }

    static void printPreOrder(Node n) {
        System.out.print(n.val + "(BF=" + balanceFactor(n) + ") ");
        if (null != n.left) {
            printPreOrder(n.left);
        }

        if (null != n.right) {
            printPreOrder(n.right);
        }
    }

    static Node insert(Node root, int val) {
        if (0 == root.val && null == root.left && null == root.right) {
            root.val = val;
        } else if (val > root.val) {
            if (null == root.right) {
                root.right = new Node();
                root.right.val = val;
            } else {
                insert(root.right, val);
            }
        } else if (val < root.val) {
            if (null == root.left) {
                root.left = new Node();
                root.left.val = val;
            } else {
                insert(root.left, val);
            }
        }

        // check the balance factor and do rotations if needed
        int balanceFactor = balanceFactor(root);
        if (-2 == balanceFactor || 2 == balanceFactor) {
            balance(root, balanceFactor);
        }

        setHeight(root);
        return root;
    }

    /**
     * Recalc the height for each ancestor
     */
    static void setHeight(Node n) {
        int hLeft  = null == n.left ? -1 : n.left.ht;
        int hRight = null == n.right ? -1 : n.right.ht;
        n.ht = Math.max(hLeft, hRight) + 1;
    }

    static int balanceFactor(Node n) {
        return (null == n.left ? -1 : n.left.ht) - (null == n.right ? -1 : n.right.ht);
    }

    static void balance(Node n, int balanceFactor) {
        if (-2 == balanceFactor) {
            if (-1 == balanceFactor(n.right)) {
                // right right case
                rotateLeft(n);
            } else {
                // right left base
                rotateRight(n.right);
                rotateLeft(n);
            }
        } else {
            if (-1 == balanceFactor(n.left)) {
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

        setHeight(n.left);
    }

    static void rotateRight(Node n) {
        Node newNode = new Node();
        newNode.val = n.val;
        newNode.right = n.right;
        newNode.left = n.left.right;

        n.val = n.left.val;
        n.left = n.left.left;
        n.right= newNode;

        setHeight(n.right);
    }

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        Node tree = new Node();

        for (int i = 0; i < n; i ++) {
            insert(tree, in.nextInt());
        }

        // insert a new number
        insert(tree, in.nextInt());
        printTree(tree);
    }
}

class Node {
    int val;     //Value
    int ht;      //Height
    Node left;   //Left child
    Node right;  //Right child
}