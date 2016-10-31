import java.lang.Long;
import java.lang.System;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringJoiner;

/**
 * @link https://code.google.com/codejam/contest/6254486/dashboard#s=p2
 */
class CoinJam {

    private static ArrayList<Long> primes = new ArrayList<>();
    private static ArrayList<String> jamCoins = new ArrayList<>();
    private static long greatestPrime;

    private static long minDivisor(long n) {
        if (primes.contains(n)) {
            return -1;
        }

        long limit = (long) Math.sqrt(n);

        if (limit > greatestPrime) {
            byte fake = 2;
            for (long j = greatestPrime + 2; j <= limit; j += 2) {
                minDivisor(j);
            }
        }

        long current = primes.get(0);
        for (int i = 0; i < primes.size() && current <= limit; current = primes.get(i++)) {
            if (0 == n % current) {
                return current;
            }
        }

        primes.add(n);
        greatestPrime = n;
        return -1;
    }

    private static boolean isJamCoin(String n) {
        long divisors[] = new long[9];
        for (byte i = 2; i <= 10; i ++) {
            long divisor = minDivisor(Long.parseLong(n, i));
            if (-1 != divisor) {
                divisors[i-2] = divisor;
            } else {
                return false;
            }
        }

        String divs = "";
        for (byte l = 0; l < 8; l ++) {
            divs += divisors[l] + " ";
        }

        divs += divisors[8];
        System.out.println(n + " " + divs);
        return true;
    }

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt(); // number of tests

        // first prime number
        primes.add(Long.valueOf("2"));
        greatestPrime = 1;

        for (int i = 1; i <= t; i ++) {
            System.out.printf("Case #%d:\n", t);
            int n = in.nextInt();
            int j = in.nextInt();

            // generate all the prime numbers <= 10^n
            long limit = (long) Math.pow(2, n);
            BigInteger generator = BigInteger.valueOf((long) Math.pow(2, n-1)+1);
            int counter = 0;
            String binNumber = generator.toString(2);

            do {
                if (isJamCoin(binNumber)) {
                    jamCoins.add(binNumber);
                    counter ++;
                }
                generator = generator.add(BigInteger.valueOf(2));
                binNumber = generator.toString(2);
            } while (generator.longValue() < limit);

            BigInteger last = generator.subtract(BigInteger.valueOf(2));
        }

        System.out.println(jamCoins.size() + " jam coins");
        //System.out.println(primes.size() + " primes");
    }
}