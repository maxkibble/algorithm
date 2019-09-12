package KotlinHero_Episode2;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        long n = in.nextLong();
        int idx = 0;
        long maxSelfie = -1;
        for (int i = 0; i < n; i++) {
            long x = in.nextLong();
            if (maxSelfie <= x) {
                maxSelfie = x;
                idx = i;
            }
        }
        if (maxSelfie == 0) out.println(0);
        else out.println(maxSelfie * n - (n - 1 - idx));
    }
}
