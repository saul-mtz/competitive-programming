import java.lang.String;
import java.lang.System;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Solution {

    private static LinkedList<Long> solution = new LinkedList<>();

    private static long serieValue(long n) {
        return n*(n+1)/2;
    }

    private static boolean isSubsetSum(long n, long sum, int b) {

        if (solution.size() > b) {
            return false;
        }

       // Base Cases
       if (sum == 0) {
           return b == solution.size();
       }

       if (n == 0 && sum != 0) {
           return false;
       }

       // If last element is greater than sum, then ignore it
       if (n-1 > sum)
         return isSubsetSum(n-1, sum, b);

       /*
       else, check if sum can be obtained by any of the following
          (a) including the last element
          (b) excluding the last element
          */
        if (isSubsetSum(n - 1, sum, b)) {
            return true;
        } else {
            solution.push(n - 1);
            if (isSubsetSum(n-1, sum-(n - 1), b)) {
                return true;
            }
            solution.pop();
            return false;
        }
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        short t = in.nextShort();

        while (t-- > 0) {

            long n = in.nextLong();   // n Sticks to buy
            long k = in.nextLong();   // k Boxes in the store for sale
            int b = in.nextInt();   // b Number of boxes to buy

            solution.clear();

            if (n > serieValue(k)) {
                System.out.println("-1");
            } else {
                isSubsetSum(k, n, b);
                if (solution.isEmpty()) {
                    System.out.println("-1");
                } else {
                    String output = String.valueOf(solution.get(0));
                    for (int i = 1; i < solution.size(); i ++) {
                        output += " " + String.valueOf(solution.get(i));
                    }

                    System.out.println(output);
                }
            }
        }
    }
}
