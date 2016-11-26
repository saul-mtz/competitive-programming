import java.util.Scanner;
import java.util.TreeMap;

/**
 * @link https://www.hackerrank.com/challenges/no-prefix-set
 * @author saul.mtz.v
 */
public class Solution {

    private static class Trie {

        // store the children nodes,
        // uses a TreeMap because the order is important
        private TreeMap<Character, Trie> children;

        // true when the current node represents a whole word
        private boolean isWord = false;

        /**
         * Default constructor, used for the root node, there is not prefix to keep
         */
        Trie() {}

        /**
         * Add a word to the current node
         *
         * @param str
         */
        public boolean add(String str) {
            Trie node = this;
            for (Character c : str.toCharArray()) {
                if (node.isWord) {
                    return false;
                }
                if (!node.contains(c)) {
                    node = node.add(c);
                } else {
                    node = node.children.get(c);
                }
            }

            if (node.isWord) {
                // the word already exists
                return false;
            } else if (null != node.children) {
                // the word is prefix of another longer word
                return false;
            } else {
                // new word
                node.isWord = true;
                return true;
            }
        }

        /**
         * Add a child to the current node
         *
         * @param c
         * @return
         */
        private Trie add(Character c) {
            if (null == children) {
                children = new TreeMap<>();
            }
            Trie child = new Trie();
            children.put(c, child);
            return child;
        }

        /**
         * Checks if the current node has a child with the key 'c'
         * @param c
         * @return
         */
        private boolean contains(Character c) {
            return null != children && children.containsKey(c);
        }

    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        Trie trie = new Trie();

        boolean goodSet = true;
        int words = in.nextInt();
        String word = null;

        while (goodSet && words -- > 0) {
            word = in.next();
            goodSet = trie.add(word);
        }

        System.out.println(goodSet ? "GOOD SET" : "BAD SET\n" + word);

    }

}
