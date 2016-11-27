import java.util.ArrayList;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/zenhacks/challenges/pairing
 */
public class Solution {

    static ArrayList<Integer> primes = new ArrayList<Integer>;

    static init() {
        primes.add(1);
        primes.add(2);
        for (int i = 3; i < Integer.MAX_VALUE; i += 2) {
            int sqrt = Math.sqrt(i);

            for (int j = 0; i )
        }
    }
    static void process(String desc, String type) {
        String pairType = type.equals("R") ? "L" : "R";
        String pairKey = desc + "-" + pairType;

        try {
            int shoeCount = shoes.get(pairKey);
            pairs++;
            if (1 == shoeCount) {
                shoes.remove(pairKey);
            } else {
                shoes.put(pairKey, shoeCount - 1);
            }
        } catch (NullPointerException e) {
            String shoeKey = desc + "-" + type;
            try {
                int shoeCount = shoes.get(shoeKey);
                shoes.put(shoeKey, shoeCount + 1);
            } catch (NullPointerException ignored) {
                shoes.put(shoeKey, 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        for (int i = 0; i < n; i++) {
            String description = in.next() + "-" + in.next() + "-" + in.next();
            String type = in.next();
            process(description, type);
        }

        System.out.println(pairs);
    }
}
