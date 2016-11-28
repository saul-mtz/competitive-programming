import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/w26/challenges/game-with-cells
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        double n = in.nextInt();
        double m = in.nextInt();

        if (0 == n || 0 == m) {
            System.out.println(0);
        } else {;
            System.out.println((int) (Math.max(1, Math.ceil(n/2)) * Math.max(1, Math.ceil(m/2))));
        }
    }

}