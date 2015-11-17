import java.util.Scanner;

/**
 * Solves the problem in:
 * @link https://www.hackerrank.com/challenges/diagonal-difference
 */
public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // matrix dimmension
	int d = in.nextInt();

        // main diagonal indexes and sum
	int i1=0, j1=0, sum1=0;

	// second diagonal indexes and sum
	int i2=0, j2=d-1, sum2=0;

	for (int i=0; i < d; i ++) {
	    for (int j=0; j<d; j ++) {
	        int val = in.nextInt();
	
	        if (i == i1 && j == j1) {
		    sum1 += val;
		    i1 ++;
		    j1 ++;
		}

		if (i == i2 && j == j2) {
		    sum2 += val;
		    i2 ++;
		    j2 --;
		}
	    }
	}

	System.out.println(Math.abs(sum1-sum2));
    }
}

