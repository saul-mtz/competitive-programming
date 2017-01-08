import java.util.*;

/**
 * @author saul.mtz.v
 */
public class Solution {

    public static void main(String args[]) {

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 1; i <= t; i ++) {
            System.out.printf("Case #%d: %s\n", i, getColor(in.nextInt(), new Point(in.nextInt(), in.nextInt())));
        }
    }

    private static String getColor(int p, Point point) {
        if (0 == p || point.magnitude > 50) {
            // out of the circle
            return "white";
        } else {
            // check if the angle is < than the one for the percentage limit
            return point.angleRadians < new Point(p).angleRadians ? "black" : "white";
        }
    }

    static class Point {

        public double x;
        public double y;
        public double magnitude;
        public double angleRadians;

        // base to cal the angle for all the points
        private static Point base = new Point(50, 100, 50);

        public Point(int x, int y, double magnitude) {
            this.x = x-50;
            this.y = y-50;
            this.magnitude = magnitude();
        }

        Point(int x, int y) {
            this.x = x-50;
            this.y = y-50;
            magnitude = magnitude();
            angleRadians = Math.acos(dotProduct(base)/(magnitude * base.magnitude));

            if (this.x < 0) {
                angleRadians = 2*Math.PI - angleRadians;
            }
        }

        public Point(double percentageFill) {
            angleRadians = percentageFill/100*Math.PI*2;
        }

        private double magnitude() {
            return Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
        }

        public double dotProduct(Point p) {
            return x*p.x + y*p.y;
        }
    }
}