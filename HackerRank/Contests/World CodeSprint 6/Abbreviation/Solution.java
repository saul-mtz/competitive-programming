import java.lang.String;
import java.lang.System;
import java.util.*;


/**
 * @author saul.martinez
 * @link   https://www.hackerrank.com/contests/world-codesprint-6/challenges/abbr
 */
public class Solution {

    private static String a, b;
    private static List<Integer> inTarget, inSource;

    private static boolean inString(String needle, String haystack, int needleIdx, int hayStackIdx) {
        for (int i = hayStackIdx; i < haystack.length(); i ++) {
            if (needle.charAt(needleIdx) == haystack.charAt(i)) {
                if (needleIdx == needle.length()-1 || inString(needle, haystack, needleIdx+1, i+1)) {
                    return true;
                }
            }
        }

        return false;
    }

    private static boolean inString(String needle, String haystack) {
        if (needle.isEmpty()) {
            return true;
        }

        for (int i = 0; i < haystack.length(); i ++) {
            if (needle.charAt(0) == haystack.charAt(i)) {
                if (1 == needle.length() || inString(needle, haystack, 1, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    private static boolean isFillable() {
        int lastTargetIdx = 0;
        int lastSrcIdx = 0;
        for (int i = 0; i < inTarget.size(); i ++) {
            int targetIdx = inTarget.get(i);
            int srcIdx = inSource.get(i);

            if (!inString(b.substring(lastTargetIdx, targetIdx).toLowerCase(), a.substring(lastSrcIdx, srcIdx))) {
                return false;
            }

            lastTargetIdx = targetIdx+1;
            lastSrcIdx = srcIdx+1;
        }

        return inString(b.substring(lastTargetIdx, b.length()).toLowerCase(), a.substring(lastSrcIdx, a.length()));
    }

    private static boolean findValidPositions(String maskStr, int offsetB, int offSetMask, int position) {
        char charToFind = maskStr.charAt(offSetMask);
        int test4 = b.length()-maskStr.length()+offSetMask;

        for (int i = offsetB; i <= test4; i ++) {
            if (b.charAt(i) == charToFind) {
                inTarget.add(position, i);
                if (position == maskStr.length()-1) {
                    if (isFillable()) {
                        return true;
                    }
                } else {
                    if (findValidPositions(maskStr, i + 1, offSetMask + 1, position + 1)) {
                        return true;
                    }
                }
                inTarget.remove(position);
            }
        }

        return false;
    }


    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        short q = in.nextShort();

        while (q-- > 0) {
            a = in.next();   // source
            b = in.next();   // target string

            String cleanedStr = "";
            inSource = new ArrayList<Integer>();
            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) < 'a') {
                    inSource.add(i);
                    cleanedStr += a.charAt(i);
                }
            }

            if (cleanedStr.length() > b.length()) {
                System.out.println("NO");
            } else if (cleanedStr.length() == b.length()) {
                System.out.println(cleanedStr.equals(b) ? "YES" : "NO");
            } else if (cleanedStr.isEmpty()) {
                System.out.println(inString(b.toLowerCase(), a) ? "YES" : "NO");
            } else {
                inTarget = new ArrayList<>(cleanedStr.length());
                boolean compatible = findValidPositions(cleanedStr, 0, 0, 0);
                System.out.println(compatible ? "YES" : "NO");
            }
        }
    }
}