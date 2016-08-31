import java.lang.System;
import java.util.Scanner;

/**
 * @author saul.martinez
 * @link   https://www.hackerrank.com/contests/world-codesprint-6/challenges/bon-appetit
 */
public class Solution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();   // test cases
        int k = in.nextInt();   // index of the item Anna did not eat

        int[] prices = new int[n];  // store all the prices
        int sum = 0;                // sum of all the account


        for (int i = 0; i < n; i ++) {
            prices[i] = in.nextInt();
            sum += prices[i];
        }

        int charged = in.nextInt(); // total charged to Anna
        int toCharge = (sum - prices[k])/2;
        System.out.println(toCharge == charged ? "Bon Appetit" : (charged-toCharge));
    }
}