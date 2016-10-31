import java.lang.System;
import java.util.Scanner;

/**
 * @link https://code.google.com/codejam/contest/4304486/dashboard#s=p0
 */
class TheLastWord {

    private static String solution(String s) {
        String solution = s.charAt(0) + "";
        for (int i = 1; i < s.length(); i ++) {
            if (s.charAt(i) < solution.charAt(0)) {
                solution += s.charAt(i);
            } else {
                solution = s.charAt(i) + solution;
            }
        }

        return solution;
    }
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        for (int i = 1; i <= t; i ++) {
            System.out.printf("Case #%d: %s\n", i, solution(in.next()));
        }
    }
}