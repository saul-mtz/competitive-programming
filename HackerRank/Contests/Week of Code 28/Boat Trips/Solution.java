import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/w28/challenges/boat-trip
 * @author saul.mtz.v
 */
public class Solution {;

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();   // number of trips
        int c = in.nextInt();   // boat capacity
        int m = in.nextInt();   // number of boats

        boolean canTransport = true;
        int maxCapacity = c*m;
        for (int i = 0; i < n && canTransport; i ++) {
            int tripSize = in.nextInt();
            if (tripSize > maxCapacity) {
                canTransport = false;
            }
        }
        System.out.println(canTransport ? "Yes" : "No");
    }
}