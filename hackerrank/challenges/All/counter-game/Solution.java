import java.math.BigInteger;
import java.util.Scanner;

/**
 * @link   https://www.hackerrank.com/challenges/counter-game
 * @author saul.martinez
 */
class Solution {


    /**
     * Return the largest power of 2 less than n
     *
     * @param n
     * @return
     */
    static long lessPowerOf2(long n) {
        long result = 0;
        while (n > 0) {
            result = n;
            n = n & (n-1);
        }
        return result;
    }

    /**
     * Check if a number is a pow of 2
     *
     * @param n
     * @return true if it is pow of 2
     */
    static boolean isPow2(long n) {
        return 0 == (n & (n-1));
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int moves;

        for (int i=0; i<t; i++) {
            String line = in.next();
            long n = Long.parseUnsignedLong(line);
            moves = 0;

            while (1 != n) {
                // overflow happends, there are two special cases
                if (n < 0) {
                    if (Long.toUnsignedString(n).equals("9223372036854775808")) {
                        // check if n == 2^63
                        // if true the new value for n is 2^62
                        n = 4611686018427387904L;
                    } else {
                        // n is > n^63, so the new value for n must be n-(n^63)
                        BigInteger bigN = new BigInteger(Long.toUnsignedString(n));
                        n = bigN.subtract(new BigInteger("9223372036854775808")).longValue();
                    }
                } else if (isPow2(n)) {
                    n >>= 1;
                } else {
                    n -= lessPowerOf2(n);
                }
                moves ++;
            }

            System.out.println((0 == (moves & 1) ? "Richard" : "Louise"));
        }
    }
}
