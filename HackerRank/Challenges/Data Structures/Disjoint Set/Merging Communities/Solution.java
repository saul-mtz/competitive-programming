import java.util.*;

/**
 * @link https://www.hackerrank.com/challenges/merging-communities
 * @author saul.mtz.v
 */
public class Solution {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int q = in.nextInt();

        DisjointSetCollection sets = new DisjointSetCollection(n);
        while (q-- > 0) {
            String queryType = in.next();
            if (queryType.equals("Q")) {
                System.out.println(sets.get(in.nextInt()).size());
            } else {
                sets.connect(in.nextInt(), in.nextInt());
            }
        }
    }

    static class DisjointSetCollection {
        public HashMap<Integer, DisjointSet> sets;

        public DisjointSetCollection(int n) {
            sets = new HashMap<>(n);
            for (int i = 1; i <= n; i ++) {
                sets.put(i, new DisjointSet(i));
            }
        }

        public DisjointSet get(Integer n) {
            return sets.get(n);
        }

        public void connect(Integer m, Integer n) {

            DisjointSet set1 = get(m);
            DisjointSet set2 = get(n);

            if (!set1.elements.equals(set2.elements)) {

                DisjointSet biggest, smallest;
                if (set1.size() > set2.size()) {
                    biggest = set1;
                    smallest = set2;
                } else {
                    biggest = set2;
                    smallest = set1;
                }

                for (Integer key : smallest.elements) {
                    sets.replace(key, biggest);
                }

                biggest.union(smallest);
            }
        }
    }

    static class DisjointSet {
        public HashSet<Integer> elements;

        public DisjointSet(Integer n) {
            elements = new HashSet<>();
            elements.add(n);
        }

        public void add(Integer n) {
            elements.add(n);
        }

        public DisjointSet union(DisjointSet set) {
            elements.addAll(set.elements);
            return this;
        }

        public int size() {
            return elements.size();
        }
    }
}