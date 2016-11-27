import java.lang.System;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/runningtime
 */
public class Solution {

    /**
     * Sort the element in the index i and returs the number of shifts made
     *
     * @param ar
     * @param l
     * @return
     */
    public static int insertIntoSorted(int[] ar, int l) {
        int val = ar[l];
        int i = l;
        int shifts = 0;

        for (; i > 0; i--) {
            if (ar[i - 1] > val) {
                ar[i] = ar[i - 1];
                shifts ++;
            } else {
                ar[i] = val;
                break;
            }
        }

        if (0 == i) {
            ar[0] = val;
        }

        return shifts;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        int[] ar = new int[s];
        int shifts = 0;

        for (int i = 0; i < s; i++) {
            ar[i] = in.nextInt();
            if (i > 0 && ar[i] < ar[i-1]) {
                shifts += insertIntoSorted(ar, i);
            }
        }

        System.out.println(shifts);
    }

}

