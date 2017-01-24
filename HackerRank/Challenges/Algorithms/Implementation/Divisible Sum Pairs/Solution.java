import java.util.HashMap;
import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/challenges/divisible-sum-pairs
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();

        HashMap<Integer, Integer> buckets = new HashMap<>(k);
        int solutions = 0;
        while (n-- > 0) {
            Integer key = in.nextInt() % k;
            Integer diffKey = (k-key) % k;

            if (buckets.containsKey(diffKey)) {
                solutions += buckets.get(diffKey);
            }

            if (buckets.containsKey(key)) {
                buckets.replace(key, buckets.get(key) + 1);
            } else {
                buckets.put(key, 1);
            }
        }
        System.out.println(solutions);
    }

}