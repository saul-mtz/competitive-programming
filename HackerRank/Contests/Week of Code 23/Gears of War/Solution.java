import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/w23/challenges/gears-of-war
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int q = in.nextInt();
        while (q-- > 0) {
            System.out.println((0 == in.nextInt()%2) ? "Yes" : "No");
        }
    }
}
