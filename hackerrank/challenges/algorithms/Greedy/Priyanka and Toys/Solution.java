import java.util.Arrays;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/priyanka-and-toys
 */
public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int weights[] = new int[n];

        for (int i = 0; i < n; i++) {
            weights[i] = in.nextInt();
        }

        Arrays.sort(weights);
        int units = 0;
        int j = 0;
        do {
            units++;
            int weight = weights[j++];
            while ((j < n) && weights[j] <= (weight + 4)) {
                j++;
            }
        } while (j < n);

        System.out.println(units);
    }
}				

