import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/minimum-average-waiting-time
 * @author saul.mtz.v
 */
public class Solution {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        PriorityQueue<Order> arrivalTimeHeap = new PriorityQueue<>(new ArrivalTimeComparator());
        PriorityQueue<Order> cookingTimeHeap = new PriorityQueue<>(new CookTimeComparator());

        for (int i = 0; i < n; i ++) {
            arrivalTimeHeap.add(new Order(in.nextLong(), in.nextLong()));
        }

        long totalWaitedTime = 0;
        long currentTime = 0;

        do {
            if (cookingTimeHeap.isEmpty() && !arrivalTimeHeap.isEmpty()) {
                cookingTimeHeap.add(arrivalTimeHeap.remove());
            }

            while (!arrivalTimeHeap.isEmpty() && arrivalTimeHeap.peek().arrivalTime <= currentTime) {
                cookingTimeHeap.add(arrivalTimeHeap.remove());
            }

            Order next = cookingTimeHeap.remove();
            if (currentTime < next.arrivalTime) {
                totalWaitedTime += next.timeToCook;
                currentTime = next.arrivalTime;
            } else {
                totalWaitedTime += (currentTime - next.arrivalTime) + next.timeToCook;
            }

            currentTime += next.timeToCook;

        } while (!arrivalTimeHeap.isEmpty() || !cookingTimeHeap.isEmpty());

        System.out.println((long) Math.floor(totalWaitedTime/n));
    }

    private static class Order {

        public long arrivalTime;
        public long timeToCook;

        Order(long arrivalTime, long timeToCook) {
            this.arrivalTime = arrivalTime;
            this.timeToCook  = timeToCook;
        }
    }

    static class ArrivalTimeComparator implements Comparator<Order> {
        @Override
        public int compare(Order a, Order b) {
            return a.arrivalTime  == b.arrivalTime ? 0 : (a.arrivalTime < b.arrivalTime ? -1 : 1);
        }
    }

    static class CookTimeComparator implements Comparator<Order> {
        @Override
        public int compare(Order a, Order b) {
            return a.timeToCook == b.timeToCook ? 0 : (a.timeToCook < b.timeToCook ? -1 : 1);
        }
    }
}