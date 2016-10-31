package com.google.codejam2015.qualification;

import java.lang.Character;
import java.lang.System;
import java.util.Scanner;

/**
 * @link https://code.google.com/codejam/contest/6224486/dashboard#s=p0
 */
class StandingOvation {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt(); // number of tests

        for (int i = 1; i <= t; i ++) {
            int shynessMax = in.nextInt();                  // max shyness for a person
            String shynessValues = in.nextLine().trim();    // shyness values

            int friendsToInvite = 0;
            int peopleStanding = 0;

            for (int j = 0; j < shynessValues.length(); j ++) {
                int peopleStandingAtJ = Character.getNumericValue(shynessValues.charAt(j));
                if (j > 0 && peopleStanding < j) {
                    int peopleToInvite = j-peopleStanding;
                    friendsToInvite += peopleToInvite;
                    peopleStanding += peopleToInvite;
                }
                peopleStanding += peopleStandingAtJ;
int a = Integer.valueOf("1");
            }
            System.out.printf("Case #%d: %d\n", i, friendsToInvite);
        }
    }
}