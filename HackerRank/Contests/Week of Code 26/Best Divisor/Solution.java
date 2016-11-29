import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/w26/challenges/best-divisor
 */
public class Solution {

    static private int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        if (n < 2) {
            System.out.println(n);
        } else {
            int maxSum = getSum(n);
            int smaller = n;

            for (int i = 2; i <= n/2; i ++) {
                if (0 == n % i) {
                    int sum = getSum(i);
                    if (sum > maxSum) {
                        maxSum = sum;
                        smaller = i;
                    }
                }
            }

            System.out.println(smaller);
        }
    }

}