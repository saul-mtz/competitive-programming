import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/insertionsort2
 */
public class Solution {

    public static void insertIntoSorted(int[] ar, int l) {
        int val = ar[l];
        int i = l;
        for (; i > 0; i--) {
            if (ar[i - 1] > val) {
                ar[i] = ar[i - 1];
            } else {
                ar[i] = val;
                break;
            }
        }

        if (0 == i) {
            ar[0] = val;
        }

        printArray(ar);

    }

    private static void printArray(int[] ar) {
        for (int n : ar) {
            System.out.print(n + " ");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        int[] ar = new int[s];
        for (int i = 0; i < s; i++) {
            ar[i] = in.nextInt();
        }

        for (int i = 1; i < s; i++) {
            insertIntoSorted(ar, i);
        }
    }

}
