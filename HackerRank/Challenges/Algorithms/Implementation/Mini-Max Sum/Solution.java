import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/challenges/mini-max-sum
 */
public class Solution {

    private static ArrayList<Long> numbers;

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        numbers = new ArrayList<>(5);
        for (int i = 0; i < 5; i ++) {
            numbers.add(in.nextLong());
        }
        Collections.sort(numbers);
        System.out.printf("%d %d\n", getMin(), getMax());
    }

    private static long getMax() {
        long sum = 0;
        for (int i = 4; i > 0; i --) {
            sum += numbers.get(i);
        }
        return sum;
    }

    private static Long getMin() {
        long sum = 0;
        for (int i = 0; i < 4; i ++) {
            sum += numbers.get(i);
        }
        return sum;
    }

}