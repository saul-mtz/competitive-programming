import java.lang.Integer;
import java.lang.System;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/challenges/largest-permutation
 */
public class Solution {

    static HashMap<Integer, ArrayList<Integer>> indexes = new HashMap<>();
    static Integer[] keys;

    static boolean permute(int index, int[] permutation) {
        int j = -1;
        for (int i = 0; i < keys.length; i ++) {
            if (indexes.containsKey(keys[i]) && !indexes.get(keys[i]).isEmpty()) {
                j = indexes.get(keys[i]).remove(0);
                break;
            } else if (indexes.containsKey(keys[i]) && indexes.get(keys[i]).isEmpty()) {
                indexes.remove(keys[i]);
            }
        }


        if (j != index && -1 != j) {
            indexes.get(permutation[index]).remove(0);
            indexes.get(permutation[index]).add(j);

            // swap the elements
            permutation[index] = permutation[index] ^ permutation[j];
            permutation[j] = permutation[index] ^ permutation[j];
            permutation[index] = permutation[index] ^ permutation[j];
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int k = in.nextInt();

        int[] permutation = new int[n];

        for (int i = 0; i < n; i++) {
            permutation[i] = in.nextInt();
            if (!indexes.containsKey(permutation[i])) {
                indexes.put(permutation[i], new ArrayList<>());
            }
            indexes.get(permutation[i]).add(i);
        }

        keys = indexes.keySet().toArray(new Integer[indexes.keySet().size()]);
        Arrays.sort(keys, java.util.Collections.reverseOrder());

        for (int i = 0; i < k && !indexes.isEmpty(); i++) {
            if (!permute(i, permutation)) {
                k ++;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            System.out.print(permutation[i] + " ");
        }
        System.out.println(permutation[n - 1]);
    }
}
