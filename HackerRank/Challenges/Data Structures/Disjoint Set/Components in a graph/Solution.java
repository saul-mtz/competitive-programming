import java.util.*;

/**
 * @link https://www.hackerrank.com/challenges/components-in-graph
 * @author saul.mtz.v
 */
public class Solution {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Graph graph = new Graph();

        while (n-- > 0) {
            graph.addEdge(in.nextInt(), in.nextInt());
        }

        System.out.println(graph.getSmallestComponent().size() + " " + graph.getBiggerComponent().size());
    }

    static class Graph {
        HashSet<Integer> elements;
        HashSet<DisjointSet> components;

        PriorityQueue<DisjointSet> minHeapComponents;
        PriorityQueue<DisjointSet> maxHeapComponents;

        public Graph() {
            elements = new HashSet<>();
            components = new HashSet<>();
            minHeapComponents = new PriorityQueue<>(new DisjointMinSizeComparator());
            maxHeapComponents = new PriorityQueue<>(new DisjointMaxSizeComparator());
        }

        public void addEdge(Integer a, Integer b) {

            DisjointSet set = new DisjointSet(a, b);
            DisjointSet componentA = findComponent(a);
            DisjointSet componentB = findComponent(b);

            if (null == componentA && null == componentB) {
                elements.add(a);
                elements.add(b);
                addComponent(set);
            } else if (null == componentB) {
                elements.add(b);

                removeComponent(componentA);
                addComponent(componentA.union(set));
            } else if (null == componentA) {
                elements.add(a);

                removeComponent(componentB);
                addComponent(componentB.union(set));
            } else {
                removeComponent(componentA);
                removeComponent(componentB);
                addComponent(componentA.union(componentB));
            }
        }

        private void removeComponent(DisjointSet component) {
            components.remove(component);
            minHeapComponents.remove(component);
            maxHeapComponents.remove(component);
        }

        private void addComponent(DisjointSet set) {
            components.add(set);
            minHeapComponents.add(set);
            maxHeapComponents.add(set);
        }

        private DisjointSet findComponent(Integer n) {
            if (elements.contains(n)) {
                for (DisjointSet set : components) {
                    if (set.find(n)) {
                        return set;
                    }
                }
            }
            return null;
        }

        public DisjointSet getSmallestComponent() {
            return minHeapComponents.peek();
        }

        public DisjointSet getBiggerComponent() {
            return maxHeapComponents.peek();
        }

        public int size() {
            return elements.size();
        }
    };

    static class DisjointSet {
        private HashSet<Integer> elements;

        public DisjointSet(Integer a, Integer b) {
            elements = new HashSet<>();
            elements.add(a);
            elements.add(b);
        }

        public void add(Integer n) {
            elements.add(n);
        }

        public boolean find(Integer n) {
            return elements.contains(n);
        }

        public DisjointSet union(DisjointSet set) {
            elements.addAll(set.getElements());
            return this;
        }

        private Collection<Integer> getElements() {
            return elements;
        }

        public int size() {
            return elements.size();
        }
    }

    static class DisjointMinSizeComparator implements Comparator<DisjointSet> {
        @Override
        public int compare(DisjointSet a, DisjointSet b) {
            return a.size() == b.size() ? 0 : (a.size() < b.size() ? -1 : 1);
        }
    }

    static class DisjointMaxSizeComparator implements Comparator<DisjointSet> {
        @Override
        public int compare(DisjointSet a, DisjointSet b) {
            return a.size() == b.size() ? 0 : (a.size() < b.size() ? 1 : -1);
        }
    }
}