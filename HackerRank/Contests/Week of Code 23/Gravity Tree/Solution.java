import java.lang.System;
import java.util.*;

/**
 * @link https://www.hackerrank.com/contests/w23/challenges/gravity-1
 */
public class Solution {

    private static Map<Integer, Node> nodes;
    private static Map<String, Node> lca;
    private static Map<String, Integer> distances = new HashMap<String, Integer>();

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        nodes = new HashMap<Integer, Node>(n);

        Node tree = new Node(1);
        tree.setHeight(0);
        nodes.put(1, tree);

        for (int i = 2; i <= n; i ++) {
            int parentId = in.nextInt();
            Node parent = getNode(parentId);
            Node child = getNode(i);
            parent.addChild(child);

            nodes.put(i, child);
            distances.put(parentId + "-" + i, 1);
        }

        int q = in.nextInt();
        while (q-- > 0) {
            Node uNode = nodes.get(in.nextInt());
            Node vNode = nodes.get(in.nextInt());
            System.out.println(vNode.getGravityTo(uNode));
        }
    }

    private static Node getNode(int nodeId) {
        if (!nodes.containsKey(nodeId)) {
            Node newNode = new Node(nodeId);
            nodes.put(nodeId, newNode);
        }

        return nodes.get(nodeId);
    }

    /**
     * Implements a tree node
     */
    private static class Node {
        public int val;
        private int height = -1;
        private Set<Node> children;
        private Node parent;

        Node(int val) {
            this.val = val;
        }

        public void addChild(Node child) {
            child.parent = this;
            if (null == children) {
                children = new HashSet<Node>();
            }
            children.add(child);
            if (height >= 0) {
                child.setHeight(height+1);
            }
        }

        public void setHeight(int height) {
            this.height = height;
            if (null != children) {
                for (Node child : children) {
                    child.setHeight(height + 1);
                }
            }
        }

        public long getGravityTo(Node node) {
            long forces = 0;

            Deque<Node> queue = new ArrayDeque<Node>();
            queue.add(this);
            while (!queue.isEmpty()) {
                Node head = queue.poll();
                Node lca = node.lca(head);
                if (null != head.children) {
                    queue.addAll(head.children);
                }
                int distance = head.val == node.val ? 0 : (head.height + node.height - 2*lca.height);
                forces += (distance*distance);
            }

            return forces;
        }

        private Node lca(Node node) {
            if (node.val == val) {
                return node;
            }

            Node higher = node.height > height ? node : this;
            Node lesser = higher.equals(node) ? this: node;

            if (node.height != height) {
                while (lesser.height != higher.height) {
                    higher = higher.parent;
                }
            }

            while (higher.val != lesser.val) {
                higher = higher.parent;
                lesser = lesser.parent;
            }

            return higher;
        }
    }

}