import java.lang.System;
import java.util.HashMap;
import java.util.Scanner;

public class Solution {

    protected static int[] heights;
    protected static HashMap<String, Integer> solutions = new HashMap<>();

    protected synchronized static int validRoutesRange(int height, int from, int to) {
        String key = height + "-" + from + "-" + to;

        if (!solutions.containsKey(key)) {
            int validRoutes = 0;

            for (int i = from; i < to; i ++) {
                for (int j = i+1; j <= to; j ++) {
                    if (heights[j] > height) {
                        break;
                    }
                    if (height == heights[i] && heights[i] == heights[j]) {
                        System.out.printf("%d,%d,%d [%d,%d]\n", height, i, j, from, to);
                        validRoutes ++;
                    }
                }
            }
            solutions.put(key, validRoutes);
        }
        return solutions.get(key);
    }

    protected synchronized static int validRoutes(int from, int to) {
        int validRoutes = 0;
        boolean first = true;

        int last = 0;
        int height = 0;
        for (int i = from; i < to; i ++) {
            for (int j = i+1; j <= to; j ++) {
                if (heights[i] != height) {
                    height= heights[i];
                    last = 0;
                }

                if (heights[j] > height) {
                    break;
                }

                if (height == heights[i] && heights[i] == heights[j] && i >= last) {
                    last = j;

                    validRoutes += validRoutesRange(height, i, j);
                    for (int k = height-1; k > 0; k --) {
                        validRoutes += validRoutesRange(k, i + 1, j - 1);
                    }

                }
            }
        }
        return validRoutes;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        heights = new int[n];
        for (int i = 0; i < n; i ++) {
            heights[i] = in.nextInt();
        }

        System.out.println(validRoutes(0, n-1)*2);

    }
}