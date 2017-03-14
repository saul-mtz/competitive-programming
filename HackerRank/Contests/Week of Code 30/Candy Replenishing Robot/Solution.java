import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/contests/w30/challenges/candy-replenishing-robot
 */
public class Solution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int t = in.nextInt();

        int added = 0;
        int b = n;
        for (int i = 1; i <= t; i ++) {
            int c = in.nextInt();
            b -= c;
            if (b < 5 && i < t) {
                added += (n-b);
                b = n;
            }
        }

        System.out.println(added);
    }

}
