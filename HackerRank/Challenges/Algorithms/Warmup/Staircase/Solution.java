import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/staircase
 */
public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int spaces = n - 1;
        int symbols = 1;

        String output = "";
        while (spaces >= 0) {
            for (int i = 0; i < spaces; i++) {
                output += ' ';
            }

            for (int i = 0; i < symbols; i++) {
                output += '#';
            }

            output += '\n';

            spaces--;
            symbols++;
        }

        System.out.println(output);
    }
}
