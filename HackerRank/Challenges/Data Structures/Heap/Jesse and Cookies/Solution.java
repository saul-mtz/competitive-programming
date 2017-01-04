import java.util.ArrayList;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/jesse-and-cookies
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        long k = in.nextInt();
        BinaryHeap bh = new BinaryHeap(n);

        while (n-- > 0) {
            bh.insert(in.nextInt());
        }

        int moves = 0;
        while (bh.size() > 1 && bh.getMinimum() < k) {
            bh.insert(bh.deleteMinimum() + 2*bh.deleteMinimum());
            moves ++;
        }

        System.out.println(bh.deleteMinimum() >= k ? moves : -1);
    }

    /**
     * min-heap implementation
     */
    private static class BinaryHeap {

        private ArrayList<Long> data;

        public BinaryHeap(int n) {
            data = new ArrayList<>(n);
        }

        public void insert(long n) {
            data.add(n);
            int index = data.size()-1;
            int indexParent = getIndexParent(index);

            while (indexParent >= 0 && n < data.get(indexParent)) {
                data.set(index, data.get(indexParent));
                data.set(indexParent, n);
                index = indexParent;
                indexParent = getIndexParent(indexParent);
            }
        }

        public long deleteMinimum() {

            long removedValue = data.get(0);

            int indexLast = 0;
            long last = data.get(data.size()-1);
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

        private int getIndexParent(int i) {
            return 0 == i%2 ? (i/2-1) : ((i-1)/2);
        }

        private int getIndexLeft(int i) {
            return i*2 + 1;
        }

        private int getIndexRight(int i) {
            return i*2 + 2;
        }

        public long getMinimum() {
            return data.get(0);
        }

        public int size() {
            return data.size();
        }
    }
}