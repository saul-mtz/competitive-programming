import java.lang.System;
import java.util.Scanner;

/**
 * @author saul.martinez
 * @link   https://www.hackerrank.com/contests/world-codesprint-6/challenges/combination-lock
 */
public class Solution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int[] currentConf = new int[5];

        for (int i = 0; i < 5; i ++) {
            currentConf[i] = in.nextInt();
        }

        int minMoves = 0;
        for (int i = 0; i < 5; i ++) {
            int finalConf = in.nextInt();
            minMoves += Math.min(
                    (finalConf >= currentConf[i] ? finalConf : finalConf+10) -currentConf[i],
                    (currentConf[i] >= finalConf ? currentConf[i] : currentConf[i]+10)-finalConf
            );
        }

        System.out.println(minMoves);
    }
}