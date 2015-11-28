import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/zenhacks/challenges/decrypt-1
 */
public class Solution
{

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        for (int i = 0; i < t; i++) {
            String p = in.next();
            String e = in.next();
            int[] diffs = new int[p.length()];
            int[] counts = new int[26];

            int max = 0;
            int shift = 0;

            for (int j = 0; j < p.length(); j++) {
                int asciiP = (int) p.charAt(j);
                int asciiE = (int) e.charAt(j);

                diffs[j] = (asciiE < asciiP) ? (asciiE + 26 - asciiP) : (asciiE - asciiP);
                counts[diffs[j]]++;

                if (counts[diffs[j]] > max) {
                    max = counts[diffs[j]];
                    shift = diffs[j];
                }
            }

            int mismatches = 0;
            for (int j = 0; j < p.length(); j++) {
                if (shift != diffs[j]) {
                    mismatches++;
                }
            }

            System.out.println(mismatches);
        }
    }
}
