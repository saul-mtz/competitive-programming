import java.util.ArrayList;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/find-the-running-median
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        MedianBinaryHeap medianHeap = new MedianBinaryHeap(n);

        while (n-- > 0) {
            System.out.printf("%.1f\n", medianHeap.insert(in.nextInt()));
        }
    }

    /**
     * min-heap implementation
     */
    private static class MedianBinaryHeap {

        private int median;
        private int size;
        MinHeap minHeap;
        MaxHeap maxHeap;

        public MedianBinaryHeap(int n) {
            minHeap = new MinHeap(n / 2);
            maxHeap = new MaxHeap(n / 2);
        }

        public double insert(int value) {
            size ++;
            if (1 == (1 & size)) {
                if (1 == size) {
                    median = value;
                } else if (value > maxHeap.root()) {
                    minHeap.insert(value);
                    median = minHeap.delete();
                } else {
                    maxHeap.insert(value);
                    median = maxHeap.delete();
                }
                return median;
            } else {
                if (value > median) {
                    minHeap.insert(value);
                    maxHeap.insert(median);
                } else {
                    minHeap.insert(median);
                    maxHeap.insert(value);
                }
                return (double) (minHeap.root() + maxHeap.root()) / 2;
            }
        }
    }

    /**
     * Common methods and properties for a Binary Heap
     */
    private static abstract class BinaryHeap {

        protected  ArrayList<Integer> data;

        protected int getIndexParent(int i) {
            return 0 == i%2 ? (i/2-1) : ((i-1)/2);
        }

        protected int getIndexLeft(int i) {
            return i*2 + 1;
        }

        protected int getIndexRight(int i) {
            return i*2 + 2;
        }

        public int root() {
            return data.get(0);
        }
    }

    /**
     * Min-Heap basic implementation
     */
    private static class MinHeap extends BinaryHeap {

        public MinHeap(int maxSize) {
            data = new ArrayList<>(maxSize);
        }

        /**
         * Insert a new value in the heap
         * @param value the value to be inserted
         */
        private void insert(int value) {
            data.add(value);
            int index = data.size() - 1;
            int indexParent = getIndexParent(index);

            while (indexParent >= 0 && value < data.get(indexParent)) {
                data.set(index, data.get(indexParent));
                data.set(indexParent, value);
                index = indexParent;
                indexParent = getIndexParent(indexParent);
            }
        }

        /**
         * Delete the min value of the heap
         * @return the deleted value
         */
        private int delete() {
            int removedValue = data.get(0);

            int indexLast = 0;
            int last = data.get(data.size()-1);
            data.set(indexLast, last);

            int indexMin;
            do {
                int indexLeft = getIndexLeft(indexLast);
                int indexRight = getIndexRight(indexLast);

                indexMin = data.size() > indexRight && data.get(indexRight) < data.get(indexLeft) ? indexRight : indexLeft;
                if (indexMin < data.size() && last >= data.get(indexMin)) {
                    data.set(indexLast, data.get(indexMin));
                    data.set(indexMin, last);
                }
                indexLast = indexMin;
            } while (indexLast < data.size() && last >= data.get(indexMin));

            data.remove(data.size()-1);
            return removedValue;
        }
    }

    /**
     * Max-Heap basic implementation
     */
    private static class MaxHeap extends BinaryHeap {

        public MaxHeap(int maxSize) {
            data = new ArrayList<>(maxSize);
        }

        /**
         * Insert a new element in the heap
         * @param value value to insert
         */
        private void insert(int value) {
            data.add(value);
            int index = data.size()-1;
            int indexParent = getIndexParent(index);

            while (indexParent >= 0 && value > data.get(indexParent)) {
                data.set(index, data.get(indexParent));
                data.set(indexParent, value);
                index = indexParent;
                indexParent = getIndexParent(indexParent);
            }
        }

        /**
         * Delete the max value of the heap
         * @return the deleted value
         */
        private int delete() {
            int removedValue = data.get(0);

            int indexLast = 0;
            int last = data.get(data.size()-1);
            data.set(indexLast, last);

            int indexMin;
            do {
                int indexLeft = getIndexLeft(indexLast);
                int indexRight = getIndexRight(indexLast);

                indexMin = data.size() > indexRight && data.get(indexRight) > data.get(indexLeft) ? indexRight : indexLeft;
                if (indexMin < data.size() && last <= data.get(indexMin)) {
                    data.set(indexLast, data.get(indexMin));
                    data.set(indexMin, last);
                }
                indexLast = indexMin;
            } while (indexLast < data.size() && last <= data.get(indexMin));

            data.remove(data.size()-1);
            return removedValue;
        }
    }
}