import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/challenges/camelcase
 */
public class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        char[] chars = in.next().toCharArray();
        int words = Character.isUpperCase(chars[0]) ? 0 : 1;
        for (Character c : chars) {
            if (Character.isUpperCase(c)) {
                words ++;
            }
        }
        System.out.println(words);
    }
}