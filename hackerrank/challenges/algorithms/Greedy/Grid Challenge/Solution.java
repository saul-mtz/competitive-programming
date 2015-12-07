import java.util.Scanner;
import java.util.Arrays;


/**
 * @link https://www.hackerrank.com/challenges/grid-challenge
 */
public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            char grid[][] = new char[n][n];
            String answer = "YES";

            for (int i = 0; i < n; i++) {
                grid[i] = in.next().toCharArray();
                Arrays.sort(grid[i]);

                if (answer.equals("YES") && i > 0) {
                    for (int j = 0; j < n; j++) {
                        if (grid[i][j] < grid[i - 1][j]) {
                            answer = "NO";
                            break;
                        }
                    }
                }
            }

            System.out.println(answer);
        }
    }
}				

