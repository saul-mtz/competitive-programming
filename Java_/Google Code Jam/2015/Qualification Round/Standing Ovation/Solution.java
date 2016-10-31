import java.lang.Character;
import java.lang.System;
import java.util.Scanner;

class Solution {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt(); // number of tests

        for (int i = 0; i < t; i ++) {
            int shynessMax = in.nextInt();                  // max shyness for a person
            String shynessValues = in.nextLine().trim();    // shyness values

            int friendsToInvite = 0;
            int peopleStanding = 0;

            for (int j = 0; j < shynessValues.length(); j ++) {
                int peopleStandingAtJ = Character.getNumericValue(shynessValues.charAt(j));
                if (peopleStanding < peopleStandingAtJ) {
                    int peopleToInvite = peopleStandingAtJ-peopleStanding;
                    friendsToInvite += peopleToInvite;
                    peopleStanding += peopleToInvite;
                }
                peopleStanding += peopleStandingAtJ;
            }
            System.out.printf("Case #%d: %d\n", i, friendsToInvite);
        }
    }
}