import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link  https://www.hackerrank.com/challenges/matrix-rotation-algo
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt()-1;
        int n = in.nextInt()-1;
        int r = in.nextInt();

        int matrix[][] = new int[m+1][n+1];
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                matrix[i][j] = in.nextInt();
            }
        }

        int min = Math.min(m+1, n+1);
        for (int layer = 0; layer < min / 2; layer ++, m --, n --) {;
            for (int j = 0; j < r % (2*(m-layer)+2*(n-layer)); j ++) {
                rotate(matrix, layer, m, n);
            }
        }

        printMatrix(matrix);
    }

    private static void rotate(int[][] matrix, int layer, int m, int n) {
        int tmp = matrix[layer][layer];

        // shift top
        for (int x = layer; x < n; x ++) {
            matrix[layer][x] = matrix[layer][x+1];
        }

        // shift right
        for (int y = layer; y < m; y ++) {
            matrix[y][n] = matrix[y+1][n];
        }

        // shift bottom
        for (int x = n; x > layer; x --) {
            matrix[m][x] = matrix[m][x-1];
        }

        // shift left
        for (int y = m; y > layer; y --) {
            matrix[y][layer] = matrix[y-1][layer];
        }

        matrix[layer+1][layer] = tmp;
    }

    private static void printMatrix(int[][] matrix) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < matrix.length; i ++) {
            for (int j = 0; j < matrix[i].length; j ++) {
                sb.append(matrix[i][j] + " ");
            }
            sb.append('\n');
        }

        System.out.println(sb.toString());
    }

}