import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/contests/w30/challenges/find-the-minimum-number
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String param1 = "int";
        String param2 = "int";

        while (n-- > 2) {
            param2 = strFunction(param1, param2);
        }

        System.out.println(strFunction(param1, param2));
    }

    static String strFunction(String param1, String param2) {
        return "min(" + param1 + ", " + param2 + ')';
    }

}
