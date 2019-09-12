import java.util.Scanner;

/**
 * @author saul.mtz.v
 * Qualification Round 2017
 *
 * @link https://code.google.com/codejam/contest/3264486
 */
public class Solution {

    private static class Range {

        private final int k;
        boolean data[];
        int from = -1;
        int to = -1;
        int unhappyLeft = 0;
        int unhappyRight = 0;
        int unhappy = 0;
        int moves = 0;

        Range(String src, int k) {
            this.k = k;
            for (int i = 0, j = src.length()-1; i <= j && (-1 == from || -1 == to); i ++, j --) {
                if ('-' == src.charAt(i) && -1 == from) {
                    from = i;
                }

                if ('-' == src.charAt(j) && -1 == to) {
                    to = j;
                }
            }

            if (-1 != from) {
                data = new boolean[getLength()];
                for (int i = 0, j = from; j <= to; i ++, j ++) {
                    if ('+' == src.charAt(j)) {
                        data[i] = true;
                    } else {
                        unhappy ++;
                        data[i] = false;
                    }
                }

                int i = 0;
                while (!data[i ++]) {
                    unhappyLeft ++;
                }

                i = data.length-1;
                while (!data[i --]) {
                    unhappyRight ++;
                }
            }
        }

        int getMoves() {
            if (0 == unhappy) {
                return 0;
            }

            boolean impossible = false;
            while (unhappy > 0 && !impossible) {
                flip(unhappyLeft >= unhappyRight);

                int n = getLength();
                if (n <= k && (unhappy > 0 && unhappy < k)) {
                    impossible = true;
                    moves = -1;
                }
            }

            return moves;
        }

        private void flip(boolean leftFlip) {
            boolean newLimit = false;
            boolean counterFinished = false;

            int n = getLength();
            for (int i = 0; i < k; i ++) {
                int index = leftFlip ? from + i : to - i;
                if (!data[index]) {
                    unhappy --;
                    data[index] = true;
                } else {
                    unhappy ++;
                    data[index] = false;
                }
            }

            if (leftFlip) {
                for (int i = from; !counterFinished && i <= to; i ++) {
                    if (newLimit) {
                        if (!counterFinished && !data[i]) {
                            unhappyLeft ++;
                        } else if (data[i]) {
                            counterFinished = true;
                        }
                    } else if (!data[i]) {
                        from = i;
                        newLimit = true;
                        unhappyLeft = 1;
                    }
                }
            } else {
                for (int i = to; !counterFinished && i >= from; i --) {
                    if (newLimit) {
                        if (!counterFinished && !data[i]) {
                            unhappyRight ++;
                        } else if (data[i]) {
                            counterFinished = true;
                        }
                    } else if (!data[i]) {
                        to = i;
                        newLimit = true;
                        unhappyRight = 1;
                    }
                }
            }

            moves ++;
        }

        public int getLength() {
            return to - from + 1;
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        for (int i = 1; i <= t; i ++) {
            Range range = new Range(in.next(), in.nextInt());
//            int moves = getMoves(in.next(), in.nextInt());
            int moves = range.getMoves();
            System.out.printf("Case #%d: %s\n", i, -1 == moves ? "IMPOSSIBLE" : moves);
        }
    }

}