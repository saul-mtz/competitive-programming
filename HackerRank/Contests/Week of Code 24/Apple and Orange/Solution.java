import java.lang.System;
import java.util.Scanner;

/**
 * Solution for Apple and Oranges
 * @link https://www.hackerrank.com/contests/w24/challenges/apple-and-orange
 */
class Solution {

    private static Scanner in;
    private static int s, t, a, b;

    private static int fallen(int rootTree, int cases) {
        int fallen = 0;
        byte position = 0;

        if (rootTree < s) {
            position = -1;
        } else if (rootTree > t) {
            position = 1;
        }

        for (int i = 0; i < cases; i ++) {
            int distance = in.nextInt();
            int fallenAt = rootTree + distance;
            if (0 == position || (s <= fallenAt && fallenAt <= t)) {
                fallen ++;
            }
        }
        return fallen;
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        s = in.nextInt();
        t = in.nextInt();
        a = in.nextInt();
        b = in.nextInt();

        int m = in.nextInt();
        int n = in.nextInt();

        System.out.println(fallen(a, m));
        System.out.println(fallen(b, n));
    }
}
