import java.util.ArrayList;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/qheap1
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        int q = in.nextInt();
        BinaryHeap bh = new BinaryHeap();

        while (q-- > 0) {
            int queryType = in.nextInt();
            switch (queryType) {
                case 1:
                    bh.insert(in.nextInt());
                    break;
                case 2:
                    bh.delete(in.nextInt());
                    break;
                default:
                    System.out.println(bh.getMinimum());
            }
        }
    }

    /**
     * min-heap implementation
     */
    private static class BinaryHeap {

        private int height = -1;
        private ArrayList<Integer> data;
        private int capacity;

        public void insert(int n) {
            if (-1 == height) {
                height = 0;
                capacity = 1;
                data = new ArrayList<Integer>(capacity);
            } else if (capacity == data.size()) {
                height ++;
                capacity += Math.pow(2, height);
                data.ensureCapacity(capacity);
            }

            data.add(n);
            int indexLast = data.size()-1;
            int indexParent = capacity/2-1;

            while (indexLast > 0 && n < data.get(indexParent)) {
                int dataParent = data.get(indexParent);
                data.set(indexParent, n);
                data.set(indexLast, dataParent);
                indexLast = indexParent;
                indexParent /= 2;
            }
        }

        public void delete(Integer n) {
            int index = data.indexOf(n);

            while (data.size() >= ((index+1)*2)) {
                int indexLeft = (index+1)*2-1;
                int indexRight = (index+1)*2;

                int indexMin = data.size() > indexRight && data.get(indexRight) < data.get(indexLeft) ? indexRight : indexLeft;
                data.set(index, data.get(indexMin));
                index = indexMin;
            }

            data.remove(index);

            if (data.size() == (capacity - Math.pow(2, height))) {
                capacity = data.size();
                height --;
            }
        }

        public int getMinimum() {
            return data.get(0);
        }
    }
}
