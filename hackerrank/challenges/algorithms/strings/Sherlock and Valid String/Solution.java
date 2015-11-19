import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/sherlock-and-valid-string
 */
public class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        String input = in.next();

        int[] count = new int[26];
        for (int i = 0; i < input.length(); i++) {
            int asciiCode = (int) input.charAt(i) - 97;
            count[asciiCode]++;
        }

        int min = Integer.MAX_VALUE, max = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] < min) {
                min = count[i];
            }

            if (count[i] > max) {
                max = count[i];
            }
        }

        boolean isValid = false;

        // all the characters have the same number of occurs
        if (min == max) {
            isValid = true;
        } else {
            int mins = 0, extra = 0;
            for (int i = 0; i < 26; i++) {
                if (min == count[i]) {
                    mins++;
                } else if (count[i] > 0) {
                    // how many chars we have to remove in order to get a valid string
                    extra += (count[i] - min);
                }
            }

            if (1 == min && 1 == mins) {
                // special case, we only have to remove one element
                isValid = true;
            } else if (extra <= 1) {
                // we only have to remove one or zero chars to get a valid string
                isValid = true;
            }
        }

        System.out.println(isValid ? "YES" : "NO");
    }

}
