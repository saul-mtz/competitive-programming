import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * @link https://www.hackerrank.com/contests/w26/challenges/twinsFloor
 */
public class Solution {

    private static LinkedHashSet<Long> primes;  // store prime numbers
    private static TreeMap<Long, Long> twins;   // V is the number of twin primes that are great or equal to K

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        long n = in.nextLong();
        long m = in.nextLong();

        if (m < 5 || (m-n) < 2) {
            System.out.println(0);
        } else {
            primes = new LinkedHashSet<>();
            primes.add((long) 2);
            primes.add((long) 3);
            primes.add((long) 5);

            twins = new TreeMap<>();
            twins.put((long)5, (long)1);

            for (long i = 7; i <= m; i += 2) {
                calcTwins(i);
            }

            Map.Entry<Long, Long> twinsLessThanM = twins.floorEntry(m);
            if (n < 5) {
                System.out.println(twinsLessThanM.getValue());
            } else {
                Map.Entry<Long, Long> twinsLessThanN = twins.floorEntry(n);
                long twinsNumber = twinsLessThanM.getValue() - twinsLessThanN.getValue();
                System.out.println(twinsNumber);
            }
        }
    }

    private static void calcTwins(long n) {
        long limit = (long) Math.sqrt(n);
        for (Long prime : primes) {
            if (0 == n % prime) {
                return;
            }

            if (prime >= limit) {
                break;
            }
        }

        primes.add(n);
        if (isPrime(n-2)) {
            twins.put(n, (long) (twins.size()+1));
        }
    }

    private static boolean isPrime(long n) {
        return primes.contains(n);
    }

}