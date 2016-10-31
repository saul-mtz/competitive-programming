import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/quicksort2
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
        if (i < j) {
            int p = partition(ar, i, j);
            quickSort(ar, i, p - 1);
            quickSort(ar, p + 1, j);
            printArray(ar, i, j);
        }
    }

    /**
     * Return the position of the pivot
     *
     * @param ar
     * @param i
     * @param j
     * @return
     */
    static int partition(int[] ar, int i, int j) {

        int[] l = new int[ar.length];
        int[] g = new int[ar.length];
        int il = 0, ig = 0;
        int pivot = ar[i];

        for (int k = i; k <= j; k++) {
            if (ar[k] < pivot) {
                l[il++] = ar[k];
            } else {
                g[ig++] = ar[k];
            }
        }

        for (int k = 0; k < il; k++) {
            ar[i++] = l[k];
        }

        ar[i] = pivot;
        il = i;
        for (int k = 0; k < ig; k++) {
            ar[i++] = g[k];
        }

        return il;
    }

    /**
     * Print the [i,j] subarray of ar
     *
     * @param ar
     */
    static void printArray(int[] ar, int i, int j) {
        for (; i <= j; i++) {
            System.out.print(ar[i] + " ");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] ar = new int[n];

        for (int i = 0; i < n; i++) {
            ar[i] = in.nextInt();
        }
        quickSort(ar, 0, n - 1);
    }
}
