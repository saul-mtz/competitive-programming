import java.util.*;

/**
 * @link https://www.hackerrank.com/challenges/contacts
 * @author saul.mtz.v
 */
public class Solution {

    static class Trie {
        // store the children nodes,
        // uses a TreeMap because the order is important
        private TreeMap<Character, Trie> children = new TreeMap();

        // prefix for the current node
        private String prefix;

        // size of the subtree, it has the value of all the subnodes from this one, included
        private int size = 1;


        /**
         * Default constructor, used for the root node, there is not prefix to keep
         */
        Trie() {
            this.prefix = "";
            size = 0;
        }

        /**
         * Creates a new node when all the descendants share the same prefix
         *
         * @param prefix
         */
        Trie(String prefix) {
            this.prefix = prefix;
        }

        /**
         * Size of all the words with the current prefix
         *
         * @return
         */
        public int size() {
            return size;
        }

        /**
         * Add a word to the current node
         *
         * @param str
         */
        public void add(String str) {
            Trie node = this;
            for (int i = 0; i < str.length(); i++) {
                Character c = str.charAt(i);
                if (!node.children.containsKey(c)) {
                    node.add(c);
                    node = node.get(c);
                } else {
                    node = node.get(c);
                    node.size++;
                }
            }

            this.size++;
        }

        /**
         * Validate if the current node or its descendants contains the word given
         *
         * @param str
         * @return Trie
         */
        public Trie search(String str) {
            Trie node = this;
            for (int i = 0; i < str.length(); i++) {
                if (node.prefix.equals(str)) {
                    return node;
                }

                Character c = str.charAt(i);
                if (!node.children.containsKey(c)) {
                    return null;
                }
                node = node.get(c);
            }

            return null == node || !node.prefix.equals(str) ? null : node;
        }

        /**
         * The prefix is used as the string value
         *
         * @return
         */
        public String toString() {
            return prefix;
        }

        /**
         * Add a new child to the current node
         *
         * @param c
         */
        private void add(char c) {
            children.put(c, new Trie(prefix + c));
        }


        private Trie get(char c) {
            return children.containsKey(c) ? children.get(c) : null;
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        Trie trie = new Trie();

        while (cases-- > 0) {
            String operation = in.next();
            String word = in.next();

            if (operation.equals("add")) {
                trie.add(word);
            } else {
                Trie prefixNode = trie.search(word);
                System.out.println(null == prefixNode ? 0 : prefixNode.size());
            }
        }
    }

}
