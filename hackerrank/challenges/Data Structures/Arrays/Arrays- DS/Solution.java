import java.util.Scanner;

/**
 * @linke https://www.hackerrank.com/challenges/arrays-dsdfdf
 */
public class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String values = "";

        for (int i = 0; i < n; i++) {
            values = in.next() + ' ' + values;
        }

        System.out.println(values.trim());
    }

}
