import java.lang.Exception;
import java.lang.Integer;
import java.lang.System;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Adobe Hackathon 2015 > A Perfect Array
 *
 * @link   https://www.hackerrank.com/contests/adobe-hackathon/challenges/golu-and-array
 * @author saul.martinez
 */
class Solution {

    static int moves = 0;
    static int values[] = new int[1000000];
    static int sortedOdd[] = new int[500000];
    static int sortedEven[] = new int[500000];
    static HashMap<Integer, Integer> map = new HashMap();
    static int n;

    static void printData() {
        for (int i = 0; i < n; i ++) {
            System.out.println("values[" + i + "]=" + values[i]);
        }

        for (int i = 0; i < n/2; i ++) {
            System.out.println("odd[" + i + "]=" + sortedOdd[i]);
        }

        for (int i = 0; i < n/2; i ++) {
            System.out.println("even[" + i + "]=" + sortedEven[i]);
        }

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey();
            int value = entry.getValue();
            System.out.println("Index of " + key + " is " + value);
        }
    }

    static void swap(int i, int value) {
        try {
            int j = map.get(value);
            values[i] = values[i]^values[j];
            values[j] = values[i]^values[j];
            values[i] = values[i]^values[j];
            map.put(values[i], i);
            map.put(values[j], j);
            moves ++;
        } catch (Exception e) {
            System.err.println("Value: " + value);
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int nEven=0, nOdd=0;

        for (int i=0; i<n; i++) {
            int value = in.nextInt();
            values[i] = value;
            map.put(value, i);

            if (0 == (value&1)) {
                sortedEven[nEven ++] = value;
            } else {
                sortedOdd[nOdd ++] = value;
            }
        }

        if (nOdd == nEven) {
            Arrays.sort(sortedEven, 0, nEven);
            Arrays.sort(sortedOdd, 0, nOdd);

            for (int i = 0, j=0, k=0; i < n; i++) {
                int sortedValue = (0 == (i & 1)) ? sortedOdd[j++] : sortedEven[k++];
                if (values[i] != sortedValue) {
                    swap(i, sortedValue);
                }
            }
        }

        System.out.println(moves);
    }
}
