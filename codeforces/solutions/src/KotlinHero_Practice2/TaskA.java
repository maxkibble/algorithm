package KotlinHero_Practice2;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt(), k = in.nextInt();
        while (k > 0) {
            if (n % 10 == 0) n /= 10;
            else n--;
            k--;
        }
        out.println(n);
    }
}
