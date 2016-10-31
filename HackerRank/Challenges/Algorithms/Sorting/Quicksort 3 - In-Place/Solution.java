import java.lang.System;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/quicksort1
 */
public class Solution {


    /**
     * Do the quicksort to ar in the [i,j] range
     *
     * @param ar
     * @param i
     * @param j
     */
    static void quickSort(int[] ar, int i, int j) {
        if (j == i || (j < i)) {
            return;
        }

        int pivot = ar[i];
        int pivotPosition = partition(ar, i, j);

        System.out.print("(" + i + "," + j + "), pivot:" + pivot + ", position:" + pivotPosition + ", "); printArray(ar, 0, ar.length-1);

        quickSort(ar, i, pivotPosition - 1);
        quickSort(ar, pivotPosition+1, j);

        printArray(ar, i, j);
    }

    /**
     * Return the position of the pivot
     * @param ar
     * @param i
     * @param j
     * @return
     */
    static int partition(int[] ar, int i, int j) {
        int pivot = ar[i];
        int index = i;
        swap(ar, i, j);
        for (int k = i; k < j; k ++) {
            if (ar[k] < pivot) {
                swap(ar, k, index);
                index ++;
            }
        }
        swap(ar, index, j);
        return index;
    }

    static void swap(int[] ar, int i, int j) {
        if (i == j) {
            return;
        }
        ar[i] = ar[i]^ar[j];
        ar[j] = ar[i]^ar[j];
        ar[i] = ar[i]^ar[j];
    }

    /**
     * Print the [i,j] subarray of ar
     * @param ar
     */
    static void printArray(int[] ar, int i, int j) {
        for (; i <= j; i ++) {
            System.out.print(ar[i] + " ");
        }
        System.out.println("");
    }

    /**
     * Do the stuff
     * @param args
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] ar = new int[n];

        for (int i = 0; i < n; i++) {
            ar[i] = in.nextInt();
        }
        quickSort(ar, 0, n-1);
    }
}
