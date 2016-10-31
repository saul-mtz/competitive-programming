import java.lang.Character;
import java.lang.Integer;
import java.lang.String;
import java.lang.System;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @link https://code.google.com/codejam/contest/6254486/dashboard
 */
class CountingSheep {

    private static void print(int nCase, String response) {
        System.out.printf("Case #%d: %s\n", nCase, response);
    }

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt(); // number of tests
        for (int i = 1; i <= t; i ++) {
            String nn = in.next();
            if (nn.equals("0")) {
                print(i, "INSOMNIA");
            } else {
                BigInteger n = new BigInteger(nn);
                ArrayList<Character> digits = new ArrayList<Character>(Arrays.asList('0','1','2','3','4','5','6','7','8','9'));
                boolean fellAsleep = false;

                do {
                    String nString = n.toString();
                    for (int j = 0; j < nString.length(); j ++) {
                        char digit = nString.charAt(j);
                        if (digits.contains(digit)) {
                            digits.remove(digits.indexOf(digit));
                        }
                    }

                    if (digits.isEmpty()) {
                        fellAsleep = true;
                        print(i, nString);
                    } else {
                        n = n.add(new BigInteger(nn));
                    }
                } while (!fellAsleep);
            }
        }
    }
}