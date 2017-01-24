import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/challenges/mars-exploration
 */
public class Solution {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        String in = scanner.next();
        int altered = 0;
        int index = 2;
        int tmp = in.length();
        while (index < in.length()) {
            if (in.charAt(index-2) != 'S') {
                altered ++;
            }

            if (in.charAt(index-1) != 'O') {
                altered ++;
            }

            if (in.charAt(index) != 'S') {
                altered ++;
            }

            index += 3;
        }
        System.out.println(altered);
    }

}