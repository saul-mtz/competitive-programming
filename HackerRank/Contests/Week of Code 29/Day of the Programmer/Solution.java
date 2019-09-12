import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

/**
 * @author saul.mtz.v
 * @link https://www.hackerrank.com/contests/w29/challenges/day-of-the-programmer
 */
public class Solution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int year = in.nextInt();
        System.out.println(getDayOfTheProgrammer(year));
    }

    private static String getDayOfTheProgrammer(int year) {
        GregorianCalendar calendar = new GregorianCalendar();
        calendar.setGregorianChange((new GregorianCalendar(1918, 0, 31)).getTime());
        calendar.set(year, 0, 1);
        
        int toAdd = 255;
        if (year < 1918) {
            toAdd -= 13;
        }
        calendar.add(Calendar.DATE, toAdd);
        return (new SimpleDateFormat("dd.MM.yyyy")).format(calendar.getTime());
    }


}
