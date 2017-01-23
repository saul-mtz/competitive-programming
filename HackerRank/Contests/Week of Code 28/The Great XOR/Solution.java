import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/w28/challenges/the-great-xor
 * @author saul.mtz.v
 */
public class Solution {;

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();

        while (q-- > 0) {
            long x = in.nextLong();
            long xCopy = x;
            long closest = 1;

            while (xCopy > 1) {
                closest <<= 1;
                xCopy >>= 1;
            }

            long solutions2 = 2*closest-x-1;
            System.out.println(solutions2);

        }
    }
}