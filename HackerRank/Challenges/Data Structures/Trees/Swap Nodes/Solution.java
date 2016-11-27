import java.util.ArrayList;
import java.util.Scanner;


/**
 * @link https://www.hackerrank.com/challenges/swap-nodes-algo
 */
public class Solution {

    static ArrayList<int[]> def;

    static int height(Node root) {
        if (null == root) {
            return 0;
        }
        return Math.max(height(root.left), height(root.right)) + 1;
    }


    static Node Insert(Node node, int label) {
        // node label
        node = new Node(label);
        // get the children data
        int[] child = def.get(label - 1);

        if (-1 != child[0]) {
            node.left = Insert(node.left, child[0]);
        }

        if (-1 != child[1]) {
            node.right = Insert(node.right, child[1]);
        }

        return node;
    }

    static void swap(Node node, int level, int currentlevel) {
        if (null == node) {
            return;
        }

        if (currentlevel == level) {
            Node tmp = node.left;
            node.left = node.right;
            node.right = tmp;
        } else {
            swap(node.left, level, currentlevel + 1);
            swap(node.right, level, currentlevel + 1);
        }
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
        def = new ArrayList<int[]>(n);

        // read and save the tree definition
        for (int i = 0; i < n; i++) {
            def.add(i, new int[]{in.nextInt(), in.nextInt()});
        }

        Node tree = Insert(null, 1);    // fill the tree
        int h = height(tree);           // height of the original tree

        // do the swaps
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int k = in.nextInt();
            int nk = k;

            while (nk < h) {
                swap(tree, nk, 1);
                nk += k;
            }

            Inorder(tree);
            System.out.println();
        }
    }
}

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
    }
}