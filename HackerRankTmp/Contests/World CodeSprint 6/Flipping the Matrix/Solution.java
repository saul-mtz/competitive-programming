import java.lang.System;
import java.util.Scanner;

/**
 * @author saul.martinez
 * @link   https://www.hackerrank.com/contests/world-codesprint-6/challenges/flipping-the-matrix
 */
public class Solution {

    /**
     * Calc the max sum
     *
     * @param matrix
     * @param n
     * @return
     */
    private static int maxSum(int[][] matrix, short n) {
        int maxSum = 0;
        int limitMatrix = 2*n-1;

        for (short i = 0; i < n; i ++) {
            for (short j = 0; j < n; j ++) {
                //System.out.printf("Para [%d][%d] las opciones son: [%d,%d],[%d,%d],[%d,%d]\n", i, j, i, limitMatrix-j, limitMatrix-i, j, limitMatrix-i, limitMatrix-j);
                maxSum += Math.max(
                        Math.max(matrix[i][j], matrix[i][limitMatrix-j]),
                        Math.max(matrix[limitMatrix-i][j],matrix[limitMatrix-i][limitMatrix-j])
                );
            }
        }

        return maxSum;
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        short q = in.nextShort();
        while (q-- > 0) {
            short n = in.nextShort();
            int matrix[][] = new int[2*n][2*n];

            for (short i = 0; i < 2*n; i ++) {
                for (short j = 0; j < 2*n; j ++) {
                    matrix[i][j] = in.nextInt();
                }
            }

            System.out.println(maxSum(matrix, n));
        }
    }
}