import java.lang.System;
import java.util.*;

/**
 * @link https://www.hackerrank.com/contests/w23/challenges/gravity-1
 */
public class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        System.out.println(maxDifference(new int[]{7,6,5,4}));
    }

    public static int maxDifference(int[] a) {
        int maxDiff = -1;
        int biggest = Integer.MIN_VALUE;
        int biggestIndex = 0;
        int smallest = Integer.MAX_VALUE;
        int smallestIndex = 0;

        for (int i = 0; i < a.length; i ++) {
            if (a[i] > biggest) {
                biggest = a[i];
                biggestIndex = i;
            }

            if (a[i] < smallest) {
                smallest = a[i];
                smallestIndex = i;
            }
        }

        for (int i = 0; i < biggestIndex; i ++) {
            maxDiff = Math.max(maxDiff, biggest - a[i]);
        }

        for (int i = smallestIndex; i < a.length-1; i ++) {
            maxDiff = Math.max(maxDiff, a[i] - smallest);
        }

        return maxDiff;
    }

}