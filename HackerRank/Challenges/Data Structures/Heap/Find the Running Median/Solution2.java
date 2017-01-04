import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/find-the-running-median
 * @author saul.mtz.v
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        MedianBinaryHeap medianHeap = new MedianBinaryHeap(n);

        while (n-- > 0) {
            System.out.printf("%.1f\n", medianHeap.add(in.nextInt()));
        }
    }

    private static class MedianBinaryHeap {

        private int median;
        private int size;
        PriorityQueue<Integer> minHeap;
        PriorityQueue<Integer> maxHeap;

        public MedianBinaryHeap(int n) {
            minHeap = new PriorityQueue<>(n / 2);
            maxHeap = new PriorityQueue<>(n/2, Collections.reverseOrder());
        }

        public double add(int value) {
            size ++;
            if (1 == (1 & size)) {
                if (1 == size) {
                    median = value;
                } else if (value > maxHeap.peek()) {
                    minHeap.add(value);
                    median = minHeap.poll();
                } else {
                    maxHeap.add(value);
                    median = maxHeap.poll();
                }
                return median;
            } else {
                if (value > median) {
                    minHeap.add(value);
                    maxHeap.add(median);
                } else {
                    minHeap.add(median);
                    maxHeap.add(value);
                }
                return (double) (minHeap.peek() + maxHeap.peek()) / 2;
            }
        }
    }
}