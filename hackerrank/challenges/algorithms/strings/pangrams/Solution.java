import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/pangrams
 */
public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String word = in.nextLine().toLowerCase();
        boolean[] chars = new boolean[26];

        for (int i = 0; i < word.length(); i++) {
            int asciiCode = (int) word.charAt(i) - 97;
            if (asciiCode >= 0) {
                chars[asciiCode] = true;
            }
        }

        boolean isPangram = true;
        for (int i = 0; i < 26; i++) {
            if (!chars[i]) {
                isPangram = false;
            }
        }
        System.out.println(isPangram ? "pangram" : "not pangram");

    }
}
