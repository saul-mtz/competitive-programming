import java.util.Scanner;

/**
 * œlink https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor
 */
public class Solution {

    static Node lca(Node root, int a, int b) {
        int h = height(root);
        Node ancestorsA[] = new Node[h], ancestorsB[] = new Node[h];

        findAncestors(root, a, ancestorsA, 0);
        findAncestors(root, b, ancestorsB, 0);

        for (int i = h - 1; i >= 0; i--) {
            if (null != ancestorsA[i] && isCommon(ancestorsA[i], ancestorsB)) {
                return ancestorsA[i];
            }
        }

        return root;
    }

    static int height(Node root) {
        if (null == root) {
            return 0;
        }
        return Math.max(height(root.left), height(root.right)) + 1;
    }

    static void findAncestors(Node n, int value, Node[] ancestors, int i) {
        ancestors[i] = n;
        if (n.data == value) {
            return;
        }
        findAncestors(value > n.data ? n.right : n.left, value, ancestors, i + 1);
    }

    static boolean isCommon(Node n, Node[] ancestors) {
        for (int i = 0; i < ancestors.length && null != ancestors[i]; i++) {
            if (n.data == ancestors[i].data) {
                return true;
            }
        }
        return false;
    }

    static Node Insert(Node n, int value) {
        if (null == n) {
            n = new Node();
            n.data = value;
        } else if (value > n.data) {
            n.right = Insert(n.right, value);
        } else if (value < n.data) {
            n.left = Insert(n.left, value);
        }

        return n;
    }

    static void Inorder(Node root) {
        if (null == root) {
            return;
        }

        Inorder(root.left);
        System.out.print(root.data + " ");
        Inorder(root.right);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Node root = new Node();
        root.data = in.nextInt();

        for (int i = 1; i < n; i++) {
            Insert(root, in.nextInt());
        }
        lca(root, 1, 2);
    }
}

class Node {
    int data;
    Node left;
    Node right;
}