package com.google.CodeJam2010.qualification;

import java.util.HashMap;
import java.util.Scanner;

/**
 * @link https://code.google.com/codejam/contest/351101/dashboard#s=p0
 */
public class StoreCredit {
    static HashMap<Integer, Integer> data;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();     // number of cases
        for (int i = 1; i <= n; i ++) {
            int c = in.nextInt(); // total credit
            int l = in.nextInt(); // items in th store

            data = new HashMap<>(l);
            boolean isSolved = false;
            for (int j = 1; j <= l; j ++) {
                int current = in.nextInt();
                if (!isSolved && data.containsKey(c-current)) {
                    isSolved = true;
                    System.out.println("Case #" + i + ": " + data.get(c-current) + " " + j);
                } else {
                    data.put(current, j);
                }
            }
        }
    }
}
