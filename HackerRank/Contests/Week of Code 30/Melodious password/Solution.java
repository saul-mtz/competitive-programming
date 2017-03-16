import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/contests/w30/challenges/melodious-password
 */
public class Solution {

    private static Character vowels[] = {'a', 'e', 'i', 'o', 'u'};
    private static Character consonants[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        buildPassword(n, 0, true, new StringBuilder());
        buildPassword(n, 0, false, new StringBuilder());
    }

    private static void buildPassword(int n, int index, boolean isVowel, StringBuilder str) {
        Character[] chars = isVowel ? vowels : consonants;
        for (int i = 0; i < chars.length; i ++) {
            str.append(chars[i]);
            if (1 == n) {
                System.out.println(str);
            } else {
                buildPassword(n-1, index+1, !isVowel, str);
            }
            str.deleteCharAt(index);
        }
    }

}