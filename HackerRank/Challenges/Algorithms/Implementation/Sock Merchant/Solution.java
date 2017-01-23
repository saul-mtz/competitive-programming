import java.util.HashSet;
import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/challenges/sock-merchant
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int pairs = 0;
        int n = in.nextInt();
        HashSet<Integer> socks = new HashSet<>();
        while (n-- > 0) {
            int color = in.nextInt();
            if (socks.contains(color)) {
                socks.remove(color);
                pairs ++;
            } else {
                socks.add(color);
            }
        }
        System.out.println(pairs);
    }

}