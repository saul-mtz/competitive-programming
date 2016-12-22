import java.util.*;

/**
 * @author  saul.mtz.v
 * @link https://www.hackerrank.com/contests/w27/challenges/getHackonacci-matrix-rotations
 */
public class Solution {

    private static boolean[] hackonacci;
    private static HashMap<Integer, Integer> changed;

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        changed = new HashMap<>();

        int n = in.nextInt();
        hackonacci = new boolean[n*n+1];
        hackonacci[1] = true;
        hackonacci[2] = false;
        hackonacci[3] = true;

        for (int i = 4; i < hackonacci.length; i ++) {
            int val1 = hackonacci[i-1] ? 1 : 0;
            int val3 = hackonacci[i-3] ? 1 : 0;
            hackonacci[i] = 1 == (1 & (val1 + val3));
        }

        boolean[][] matrix = hackonacciMatrix(n);
        int q = in.nextInt();

        while (q-- > 0) {
            System.out.println(getDifferentCells(matrix, in.nextInt() % 360));
        }
    }

    private static int getDifferentCells(boolean[][] matrix, int angle) {
        if (0 == angle) {
            return 0;
        }

        if (!changed.containsKey(angle)) {
            changed.put(angle, rotate(matrix, angle));
        }
        return changed.get(angle);
    }

    private static boolean getHackonacci(int n) {
        return 0 != (n + 4) % 7 && hackonacci[n];
    }

    private static boolean[][] hackonacciMatrix(int n) {
        boolean[][] matrix = new boolean[n][n];
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                matrix[i][j] = getHackonacci((i + 1) * (j + 1));
            }
        }
        return matrix;
    }


    private static int rotate(boolean[][] matrix, int grades) {

        int changed = 0;
        boolean rotated;
        for (int i = 0, x = matrix.length - 1; i < matrix.length; i ++, x --) {
            for (int j = 0, y = matrix[i].length - 1; j < matrix[i].length; j++, y--) {
                switch (grades) {
                    case 90:
                        rotated = matrix[y][i];
                        break;
                    case 180:
                        rotated = matrix[x][y];
                        break;
                    default:
                        rotated = matrix[j][x];
                }

                if (rotated != matrix[i][j]) {
                    changed ++;
                }
            }
        }

        return changed;
    }

}