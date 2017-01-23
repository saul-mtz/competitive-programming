import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/challenges/compare-the-triplets
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        Triplet alice = new Triplet(in.nextInt(), in.nextInt(), in.nextInt());
        Triplet bob = new Triplet(in.nextInt(), in.nextInt(), in.nextInt());

        System.out.printf("%d %d\n", alice.getPoints(bob), bob.getPoints(alice));
    }

    private static class Triplet {
        public final int a;
        public final int b;
        public final int c;

        Triplet(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public int getPoints(Triplet other) {
            int points = 0;

            if (a > other.a) {
                points ++;
            }

            if (b > other.b) {
                points ++;
            }

            if (c > other.c) {
                points ++;
            }

            return points;
        }
    }
}