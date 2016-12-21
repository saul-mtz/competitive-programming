import java.util.*;

/**
 * @author  saul.mtz.v
 * @link https://www.hackerrank.com/contests/w27/challenges/tailor-shop
 */
public class Solution {

    private static HashSet<Integer> buttons;
    private static TreeMap<Integer, Integer> minButtons;

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        double p = in.nextDouble();

        int cost = 0;
        buttons = new HashSet<>();
        minButtons = new TreeMap<>();

        while (n-- > 0) {
            int a = in.nextInt();
            int minForPrice = (int) Math.ceil(a/p);
            int minAvailable;

            if (buttons.contains(minForPrice)) {
                if (null == minButtons.ceilingKey(minForPrice)) {
                    minForPrice = minButtons.floorKey(minForPrice);
                } else {
                    minForPrice = minButtons.ceilingKey(minForPrice);
                }
                minAvailable = minButtons.get(minForPrice);
            } else {
                minAvailable = minForPrice;
            }

            cost += minAvailable;
            buttons.add(minAvailable);
            addMin(minForPrice, minAvailable + 1);
        }

        System.out.println(cost);
    }

    private static void addMin(int key, int value) {
        minButtons.put(key, value);
        if (buttons.contains(value)) {
            minButtons.remove(key);
        }

        if (minButtons.containsValue(key)) {
            int lessKey = minButtons.lowerKey(key);
            minButtons.remove(lessKey);
        }
    }

}