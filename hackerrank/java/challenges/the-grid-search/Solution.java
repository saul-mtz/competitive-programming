import java.util.Scanner;

/**
 * @link   https://www.hackerrank.com/challenges/the-grid-search
 * @author saul.martinez
 */
class Solution {

    /**
     * Find out if substr is a substring of str
     *
     * @param str
     * @param substr
     * @return integer > 0 if the substring occurs
     */
    static int substring(String str, String substr) {
        for (int i = 0; i <= (str.length()-substr.length()); i ++) {
            boolean match = true;
            for (int j = 0; j < substr.length(); j ++) {
                if (str.charAt(i+j) != substr.charAt(j)) {
                    match = false;
                    break;
                }
            }

            if (match) {
                return i;
            }
        }

        return -1;
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        byte t = in.nextByte(); // test cases

        for (int i=0; i<t; i++) {

            /* read and store the main grid */
            short R = in.nextShort();
            short C = in.nextShort();
            in.nextLine();
            String[] grid = new String[R];
            for (int j=0; j<R; j++) {
                // store each matrix row as a string
                grid[j] = in.nextLine();
            }

            /* read and store the subgrid to find */
            short r = in.nextShort();
            short c = in.nextShort();
            String[] subrid = new String[r];
            in.nextLine();
            for (int j=0; j<r; j++) {
                // store each matrix row as a string
                subrid[j] = in.nextLine();
            }

            int j = 0;
            String result = "NO";
            while (j < (R-r+1)) {
                int m = substring(grid[j], subrid[0]);

                // the first subgrid row is a substring of the current analized for grid
                // try to match the next rows
                if (m >= 0) {
                    boolean match = true;
                    for (int k = 1; k < r && match; k++) {
                        if (!grid[j+k].substring(m, m+c).equals(subrid[k])) {
                            match = false;
                        }
                    }

                    if (match) {
                        result = "YES";
                        break;
                    }
                }
                j ++;
            }

            System.out.println(result);
        }
    }
}
