import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/funny-string
 */
public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // test cases
        int n = in.nextInt();

        // read the words and print the result
        for (int i = 0; i < n; i++) {
            boolean funny = true;
            String word = in.next();

            int l = word.length();
            for (int j = 0, k = l - 1; j < l - 1; j++, k--) {
                int diff1 = Math.abs((int) word.charAt(j) - (int) word.charAt(j + 1));
                int diff2 = Math.abs((int) word.charAt(k) - (int) word.charAt(k - 1));

                if (diff1 != diff2) {
                    funny = false;
                    break;
                }
            }

            System.out.println(funny ? "Funny" : "Not Funny");
        }
    }
}

