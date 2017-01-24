import java.util.HashSet;
import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/challenges/journey-to-the-moon
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int i = in.nextInt();
        DisjointSetCollection sets = new DisjointSetCollection(n);

        while (i-- > 0) {
            sets.add(new DisjointSet(in.nextInt(), in.nextInt()));
        }

        long sum = 0;
        for (DisjointSet set : sets.sets) {
            sum += binomialCoefficient(set.elements.size());
        }

        System.out.print(binomialCoefficient((long)n)-sum);
    }

    private static long binomialCoefficient(long n) {
        return (n*(n-1))/2;
    }

    static class DisjointSetCollection {
        private final HashSet<DisjointSet> sets = new HashSet<>();
        private final DisjointSet unknown;

        public DisjointSetCollection(int size) {
            unknown = new DisjointSet(size);
        }

        public void add(DisjointSet newSet) {
            unknown.remove(newSet.first);
            unknown.remove(newSet.second);

            DisjointSet setFirst = find(newSet.first);
            DisjointSet setSecond = find(newSet.second);

            if (null == setFirst && null == setSecond) {
                sets.add(newSet);
            } else {
                if (null == setFirst) {
                    setSecond.union(newSet);
                } else if (null == setSecond) {
                    setFirst.union(newSet);
                } else if (!setFirst.elements.equals(setSecond.elements)) {
                    setFirst.union(setSecond);
                    sets.remove(setSecond);
                }
            }
        }

        private DisjointSet find(Integer value) {
            for (DisjointSet s : sets) {
                if (s.find(value)) {
                    return s;
                }
            }

            return null;
        }
    }

    static class DisjointSet {
        public final HashSet<Integer> elements;
        public int first;
        public int second;

        public DisjointSet(int i, int j) {
            first = i;
            second = j;
            elements = new HashSet<>(2);
            elements.add(first);
            elements.add(second);
        }

        public DisjointSet(int n) {
            elements = new HashSet<>(n);
            for (int i = 0; i < n; i ++) {
                elements.add(i);
            }
        }

        public void union(DisjointSet set) {
            elements.addAll(set.elements);
        }

        public boolean find(int element) {
            return elements.contains(element);
        }

        public void remove(int element) {
            elements.remove(element);
        }
    }
}