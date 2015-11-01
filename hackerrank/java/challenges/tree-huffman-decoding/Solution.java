import java.lang.System;
import java.util.Scanner;

/**
 * Tree: Huffman Decoding
 *
 * @link   https://www.hackerrank.com/challenges/tree-huffman-decoding
 * @author saul.martinez
 */
class Solution {

    static public class Node {
        public int frequency;
        public char data = '\u0000';
        public Node left, right;

        public Node(char data, int frequency) {
            this.data = data;
            this.frequency = frequency;
        }

        public Node(int frequency) {
            this.frequency = frequency;
        }
    }

    static Node buildTest() {
        Node cNode = new Node('C', 1);
        Node bNode = new Node('B', 1);

        Node childL = new Node(2);
        childL.left = bNode;
        childL.right = cNode;

        Node root = new Node(5);
        root.left = childL;
        root.right = new Node('A', 3);

        return root;
    }

    static void decode(String S, Node root) {
        int n = S.length();
        String decoded = "";

        Node node = root;
        for (int i = 0; i < n; i ++) {
            if ('0' == S.charAt(i)) {
                node = node.left;
            } else {
                node = node.right;
            }

            if ('\u0000' != node.data) {
                decoded += node.data;
                node = root;
            }
        }

        System.out.println(decoded);
    }

    static void printTree(Node r) {
        if ('\u0000' == r.data) {
            System.out.println("Internal node, frequency " + r.frequency);
        } else {
            System.out.println("Leaf node, value " + r.data + ", frequency " + r.frequency);
        }

        if (null != r.left) {
            printTree(r.left);
        }

        if (null != r.right) {
            printTree(r.right);
        }
    }

    public static void main (String[] args) {
        buildTest();
        Node tree = buildTest();
        decode("1001011", tree);
    }
}
