import java.util.Scanner;
import java.math.BigInteger;

/**
 * @link https://www.hackerrank.com/challenges/fibonacci-modified
 */
public class Solution {

    private static BigInteger[] fibs;

    static BigInteger fibonacci(int n) {
        if (null != fibs[n]) {
            return fibs[n];
        }

        fibs[n] = fibonacci(n - 1).pow(2).add(fibonacci(n - 2));
        return fibs[n];
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        String a = in.next();
        String b = in.next();
        int n = in.nextInt();

        fibs = new BigInteger[n];
        fibs[0] = new BigInteger(a);
        fibs[1] = new BigInteger(b);

        System.out.println(fibonacci(n-1));
    }

}
