import java.util.Scanner;

/**
 * @link   https://www.hackerrank.com/challenges/utopian-tree
 * @author saul.martinez
 */
class Solution {

    static int values[] = new int[61];

    static int solve(int n) {
        if (0 == values[n]) {
            if (0 == (n & 1)) {
                values[n] = solve(n-1) + 1;
            } else {
                values[n] = 2*solve(n-1);
            }
        }

        return values[n];
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        byte t = in.nextByte(); // test cases
        values[0] = 1;
        for (int i=0; i<t; i++) {
            int n = in.nextByte();
            System.out.println(solve(n));
        }
    }
}
