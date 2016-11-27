import java.lang.System;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/w23/challenges/commuting-strings
 */
public class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        String s = in.next();
        int m = in.nextInt();

        String t = getStrGenerator(s, m);
        System.out.println(m/t.length() % 1000000007);
    }

    private static String getStrGenerator(String s, int m) {
        for (int i = 1; i <= m; i ++) {
            String t = s.substring(0, i);
            if (s.concat(t).equals(t.concat(s))) {
                return t;
            }
        }

        return s;
    }

}