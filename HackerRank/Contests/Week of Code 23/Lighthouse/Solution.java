import java.lang.System;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/w23/challenges/lighthouse
 */
public class Solution {

    private static boolean matrix[][];

    private static int solution() {
        int i;
        for (i = matrix.length/2; i > 0; i --) {
            if (solution(i)) {
                break;
            }
        }

        return i;
    }

    private static boolean solution(int n) {
        int length = matrix.length-2*n;
        for (int i = 0; i < length; i ++) {
            for (int j = 0; j < length; j ++) {
                //printCircle(i, j, n);
                if (isSolution(i, j, n)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean isSolution(int row, int col, int rad) {
        int centerX = row+rad;
        int centerY = col+rad;
        int n = 2*rad + 1;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int currentX = row + i;
                int currentY = col + j;
                if (distance(centerX, centerY, currentX, currentY) <= rad && !matrix[currentX][currentY]) {
                    return false;
                }
            }
        }

        return true;
    }

    private static void printCircle(int row, int col, int rad) {
        int centerX = row+rad;
        int centerY = col+rad;
        System.out.printf("rad %d, starting at [%d, %d], center: [%d,%d] ...\n", rad, row, col, centerX, centerY);
        int n = 2*rad + 1;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int currentX = row + i;
                int currentY = col + j;
                if (distance(centerX, centerY, currentX, currentY) <= rad) {
                    double test = distance(centerX, centerY, currentX, currentY);
                    System.out.print(matrix[currentX][currentY] ? '.' : '*');
                } else {
                    System.out.print(' ');
                }
            }
            System.out.println();
        }
    }

    private static double distance(int centerX, int centerY, int pointX, int pointY) {
        return Math.sqrt(Math.pow(centerX-pointX, 2) + Math.pow(centerY-pointY, 2));
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        short n = in.nextShort();

        matrix = new boolean[n][n];

        for (short i = 0; i < n; i ++) {
            String line = in.next();
            for (short j = 0; j < n; j ++) {
                matrix[i][j] = line.charAt(j) == '.';
            }
        }

        System.out.println(solution());

    }

}