import java.util.Scanner;

/**
 * @link   https://www.hackerrank.com/challenges/and-product
 * @author saul.martinez
 */
class Solution {


    static byte log2(long n) {
        byte r = 0;
        while (n > 0) {
            n >>= 1;
            r++;
        }
        return r;
    }

    static long getMask(byte log2) {
        long mask = Long.MAX_VALUE;
        while (log2 > 0) {
            mask <<= 1;
            log2 --;
        }
        return mask;
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        short t = in.nextShort();

        for (short i = 0; i < t; i ++) {
            long a = in.nextLong();
            long b = in.nextLong();
            if (0 == a) {
                System.out.println(0);
            } else if (a == b) {
                System.out.println(0);
            } else {
                byte log2 = log2(b-a);
                long mask = getMask(log2);
                long r = a & b & mask;
                //System.out.println(a + " " + b + ", " + Long.toBinaryString(a) + "&" + Long.toBinaryString(b) + "&" + Long.toBinaryString(mask) + "=" + Long.toBinaryString(r) + " " + r);
                System.out.println(r);
            }
        }
    }

}
