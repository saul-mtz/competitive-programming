import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/quicksort1
 */
public class Solution {

    static void partition(int[] ar, int p) {
        int[] a = new int[ar.length];
        int i = 0, j = ar.length - 1;
        for (int k = 1; k < ar.length; k ++) {
            if (ar[k] < p) {
                a[i++] = ar[k];
            } else {
                a[j--] = ar[k];
            }
        }

        a[i] = p;
        printArray(a);
    }

    static void printArray(int[] ar) {
        for (int n : ar) {
            System.out.print(n + " ");
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
        partition(ar, ar[0]);
    }
}
