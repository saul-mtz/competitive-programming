import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/plus-minus
 */
public class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int positives = 0, negatives = 0, zeros = 0;

        for (int i = 0; i < n; i++) {
            int val = in.nextInt();
            if (val > 0) {
                positives++;
            } else if (val < 0) {
                negatives++;
            } else {
                zeros++;
            }
        }

        System.out.format("%.3f%n", (float) positives / n);
        System.out.format("%.3f%n", (float) negatives / n);
        System.out.format("%.3f%n", (float) zeros / n);
    }

}

