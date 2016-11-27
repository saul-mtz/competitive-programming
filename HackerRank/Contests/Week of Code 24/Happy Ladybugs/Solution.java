import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Happy Ladybugs
 *
 * @link https://www.hackerrank.com/contests/w24/challenges/happy-ladybugs
 */
class Solution {

    private static Scanner in;
    private static Map<Character, Integer> counter;

    private static String solution() {
        int n = in.nextInt();
        int spaces = 0;
        counter = new HashMap();

        String b = in.next();
        char prev = b.charAt(0);
        boolean inOrder = true;
        boolean checkNext = false;

        for (int j = 0; j < n; j ++) {
            char c = b.charAt(j);
            if ('_' == c) {
                spaces ++;
            } else {
                if (!counter.containsKey(c)) {
                    counter.put(c, 0);
                }

                if (checkNext) {
                    checkNext = false;
                    if (c != prev) {
                        inOrder = false;
                    }
                }

                if (c != prev) {
                    checkNext = true;
                }

                counter.put(c, counter.get(c) + 1);
            }
            prev = c;
        }


        // no chars
        if (0 == counter.size()) {
            return "YES";
        }

        // we need at least two chars for each letter
        for (Map.Entry<Character, Integer> entry : counter.entrySet()) {
            if (1 == entry.getValue()) {
                return "NO";
            }
        }

        // all the chars are the same
        if (1 == counter.size()) {
            return "YES";
        }

        // the chars are sorted
        if (inOrder) {
            return "YES";
        }

        // wee need at least one space and two of every different char
        return 0 == spaces ? "NO" : "YES";
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        int g = in.nextInt();

        for (int i = 0; i < g; i ++) {
            System.out.println(solution());
        }
    }
}