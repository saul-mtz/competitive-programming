import static junit.framework.TestCase.assertEquals;

/**
 * 23-nov-2016 Challenge
 *
 * Solved using bitwise operations
 *
 * @link https://codefights.com/challenge/y4q97ZToigDhSPSHc
 */
public class Solution {

    static int bitWork(String instructions) {
        int result = asciiSum(instructions);

        StringBuilder sb = new StringBuilder(instructions);
        while (sb.length() > 0) {
            String rule = nextToken(sb);
            String value = nextNumber(sb);
            result = updateValue(rule, Integer.parseInt(value), result);
        }

        return result ^= 1 << instructions.length();
    }

    private static int updateValue(String rule, int value, int result) {
        switch (rule) {
            case "&" : return value & result;
            case "|" : return value | result;
            case "^" : return value ^ result;
            case "<<": return result << value;
            case ">>": return result >> value;
            case "SB": return result | 1 << value;
            case "CB": return result & ~(1 << value);
        }
        return result;
    }

    private static void reverseBit(StringBuilder bin, int nn) {
        int n = bin.length()-nn-1;
        int c = bin.charAt(n);
        if (48 == c) {
            bin.setCharAt(n, '1');
        } else {
            bin.setCharAt(n, '0');
        }
    }

    private static int asciiSum(String token) {
        int sum = 0;
        for (int i = 0; i < token.length(); i ++) {
            sum += token.charAt(i);
        }
        return sum;
    }

    private static String nextToken(StringBuilder sb) {
        Character c = sb.charAt(0);

        if (c >= 48 && c <= 57) {
            return "";
        }

        switch (c) {
            case '&':
            case '|':
            case '^':
                sb.deleteCharAt(0);
                return String.valueOf(c);
        }

        String str = sb.substring(0, 2);
        sb.delete(0, 2);
        return str;
    }

    private static String nextNumber(StringBuilder sb) {
        int index = 0;
        Character c;
        do {
            c = sb.charAt(index++);
        } while (index < sb.length() && c >= 48 && c <= 57);

        String str = sb.substring(0, index < sb.length() ? index - 1 : index);
        sb.delete(0, index < sb.length() ? index - 1 : index);
        return str;
    }

    public static void main(String args[]) {
        assertEquals(bitWork("SB16"), 65772);
        assertEquals(bitWork("|12<<3&510>>2SB10^6CB4"), 4195432);
        assertEquals(bitWork("<<8|9>>10^11"), 4299);
        assertEquals(bitWork("255"), 148);
        assertEquals(bitWork("1"), 51);
    }

}