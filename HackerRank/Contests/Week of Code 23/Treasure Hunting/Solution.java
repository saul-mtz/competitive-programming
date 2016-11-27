import java.lang.System;
import java.util.Scanner;

/**
 * @link https://www.hackerrank.com/contests/w23/challenges/treasure-hunting
 */
public class Solution {

    private static class Line {
        public double m;
        public double h;

        Line(double m, double h) {
            this.m = m;
            this.h = h;
        }

        public String toString() {
            return "y = " + m + "x + " + h;
        }

        public double eval(double x) {
            return m*x + h;
        }

        public Point intersect(Line l) {
            double x = (l.h - h)/(m - l.m);
            return new Point(x, l.eval(x));
        }

        public boolean contains(Point target) {
            return this.eval(target.x) == target.y;
        }
    }

    private static class Point {
        public double x;
        public double y;
        public double d;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
            this.d = (0 == x && 0 == y) ? 0 : this.distance(new Point(0,0));
        }

        public String toString() {
            return "[" + x + "," + y + "]";
        }

        public double distance(Point to) {
            return Math.sqrt(Math.pow(this.x-to.x, 2) + Math.pow(this.y-to.y, 2));
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        Point target = new Point(in.nextDouble(), in.nextDouble());
        Point dVector = new Point(in.nextDouble(), in.nextDouble());

        Line l1 = new Line(dVector.y/dVector.x, 0);

        if (!l1.contains(target)) {
            Line l2 = new Line(-1 / l1.m, target.y + (1 / l1.m) * target.x);

            //System.out.println("v1 = " + v1);
            //System.out.println("v2 = " + v2);

            Point intersection = l1.intersect(l2);
            //System.out.println(intersection);

            System.out.println(intersection.d/dVector.d);
            double n = intersection.distance(target)/dVector.d;
            System.out.println(intersection.y < target.y ? n : n*-1);
        } else {
            System.out.println(target.d/dVector.d);
            System.out.println(0);
        }
    }

}