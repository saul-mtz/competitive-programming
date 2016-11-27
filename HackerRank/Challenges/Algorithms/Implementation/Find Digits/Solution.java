import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/find-digits
 */
public class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        for (int i = 0; i < t; i++) {
            int digits = 0;
            String number = in.next();
            int n = Integer.parseInt(number);

            for (int j = 0; j < number.length(); j++) {
                int digit = (int) number.charAt(j) - 48;

                if (0 != digit && 0 == n % digit) {
                    digits++;
                }
            }

            System.out.println(digits);
        }
    }
}

