import java.lang.Exception;
import java.lang.Integer;
import java.lang.System;
import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

/**
 * @link https://code.google.com/codejam/contest/4304486/dashboard#s=p0
 */
class RankAndFile {

    private static ArrayList<ArrayList<Integer>> lists;
    private static int matrix[][];

    private static String solution(ArrayList<ArrayList<Integer>> lists, int n) {
        lists.sort(new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
                boolean equals = true;
                for (int i = 0; i < a.size(); i ++) {
                    if (a.get(i) < b.get(i)) {
                        return -1;
                    } else if (a.get(i) != b.get(i)) {
                        equals = false;
                    }
                }

                return equals ? 0 : 1;
            }
        });

        matrix = new int[n][n];
        int lastIndex = lists.size()-1;
        for (int i = 0; i < n; i ++) {
            matrix[0][i] = lists.get(0).get(i);
            matrix[0][i] = lists.get(lastIndex).get(i);
        }

        ArrayList<ArrayList<Integer>> candidates = new ArrayList(lists);
        candidates.remove(lastIndex);
        candidates.remove(0);

        ArrayList<Integer> missig = new ArrayList<>(n*2);

        for (int i = 0; i < missig.size(); i ++) {
            missig.add(i);
        }
        missig.remo

        System.out.println(candidates);
        System.out.println(lists);

        return listToString(solution(candidates, 0, n-1, -1));
    }

    private static ArrayList<Integer> solution(ArrayList<ArrayList<Integer>> available, int columnIndex, int n, int hole) throws Exception {

        if (columnIndex == n) {
            ArrayList<Integer> solution = new ArrayList<>(n);
            for (int i = 0; i <= n; i ++ ) {
            }
            return solution;
        }

        int startWith = matrix[0][columnIndex];
        int endWith = matrix[n][columnIndex];
        ArrayList<Integer> solution;
        ArrayList<ArrayList<Integer>> candidates = getCandidates(available, startWith, endWith, n);

        if (0 == candidates.size()) {
            if (-1 != hole) {
                throw new Exception();
            } else {
                hole = columnIndex;
            }
        }

        for (int i = 0; i < candidates.size(); i ++) {
            try {
                ArrayList<Integer> candidate = candidates.get(i);
                for (int j = 0; j < candidate.size(); j++) {
                    matrix[columnIndex][j] = candidate.get(j);
                }
                available.remove(candidates.get(i));
                return solution(available, columnIndex + 1, n, hole);
            } catch (Exception ignored);
        }
    }

    private static ArrayList<ArrayList<Integer>> getCandidates(ArrayList<ArrayList<Integer>> available, int startWith, int endWith, int n) {
        ArrayList<ArrayList<Integer>> candidates = new ArrayList<>();

        for (int i = 0; i < available.size(); i ++) {
            ArrayList<Integer> current = available.get(i);
            if (startWith == current.get(0) && endWith == current.get(n)) {
                candidates.add(current);
            }
        }

        return candidates;
    }

    private static String listToString(ArrayList<Integer> list) {
        String s = String.valueOf(list.get(0));
        for (int i = 1; i < list.size(); i ++) {
            s += " " + list.get(i);
        }
        return s;
    }

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        for (int i = 1; i <= t; i ++) {
            int n = in.nextInt();
            lists = new ArrayList<>(n);

            int k = 0;
            for (; k < 2*n-1; k ++) {
                ArrayList<Integer> list = new ArrayList<>(n);
                for (int j = 0; j < n; j ++){
                    list.add(in.nextInt());
                }
                lists.add(list);
            }
            System.out.printf("Case #%d: %s\n", i, solution(lists, (int)Math.sqrt(k)+1));
        }
    }
}