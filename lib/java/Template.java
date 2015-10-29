import java.util.Scanner;

class SolutionTemplate {

    static int solve(int a, int b) {
        return a+b;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t;
        int sum;
        int a,b;
        t = in.nextInt();

        for (int i=0; i<t; i++) {
            a = in.nextInt();
            b = in.nextInt();
            sum = solve(a, b);
            System.out.println(sum);
        }
    }
}
