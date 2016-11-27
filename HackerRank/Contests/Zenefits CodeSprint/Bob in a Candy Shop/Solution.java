import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/zenhacks/challenges/candy-shop
 */
public class Solution {

    private static int[] bills = {1, 2, 5, 10, 20, 50, 100};
    private static int n;
    private static int count;

    static void sum(int total, int index) {
        for (int i = index; i < 7; i++) {
            if ((total + bills[i]) < n) {
                sum(total + bills[i], i);
            } else if ((total + bills[i]) == n) {
                count++;
            } else {
                return;
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        sum(0, 0);
        System.out.println(count);
    }
}
