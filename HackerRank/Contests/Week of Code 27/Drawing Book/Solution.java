import java.util.Scanner;

//import static junit.framework.TestCase.assertEquals;

/**
 * @author  saul.mtz.v
 * @link https://www.hackerrank.com/contests/w27/challenges/drawing-book
 */
public class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        System.out.println(solution(in.nextInt(), in.nextInt()));
/*
        assertEquals(solution(100, 1), 0);
        assertEquals(solution(100, 2), 1);
        assertEquals(solution(100, 3), 1);
        assertEquals(solution(100, 4), 2);
        assertEquals(solution(100, 5), 2);

        assertEquals(solution(100, 100), 0);
        assertEquals(solution(100, 99), 1);
        assertEquals(solution(100, 98), 1);
        assertEquals(solution(100, 97), 2);
        assertEquals(solution(100, 96), 2);

        assertEquals(solution(101, 101), 0);
        assertEquals(solution(101, 100), 0);
        assertEquals(solution(101, 99), 1);
        assertEquals(solution(101, 98), 1);
        assertEquals(solution(101, 97), 2);
        assertEquals(solution(101, 96), 2);
*/
    }

    private static int solution(int n, int p) {
        return (1 == p || n == p) ? 0 : Math.min(p/2, (0 == n % 2 ? (n-p+1) : n-p)/2);
    }

}