import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * @author saul.mtz.v
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        for (int i = 1; i <= t; i ++) {
            int n = in.nextInt();
            LinkedList<Integer> weights = new LinkedList<>();
            while (n-- > 0) {
                weights.add(in.nextInt());
            }

            Collections.sort(weights);
            int trips = 0;
            int topWeight = 0;
            int weight = -1;

            while (!weights.isEmpty()) {

                if (weight == -1) {
                    topWeight = weights.removeLast();
                    weight = 0;
                } else {
                    weights.removeFirst();
                }

                weight += topWeight;
                if (weight >= 50) {
                    trips ++;
                    weight = -1;
                }
            }

            System.out.printf("Case #%s: %d\n", i, trips);
        }
    }
}