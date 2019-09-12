package KotlinHero_Practice2;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskF {

    long lower(long x) {
        long ret = 1;
        while (x >= ret) {
            ret = ret * 10 + 1;
        }
        ret = (ret - 1) / 10;
        return ret;
    }

    long f(long x, long y) {
        if (x == 0) return 0;
        long l = lower(x), u = l * 10 + 1;
        long a = Long.toString(l).length(), b = a + 1;
        a = x / l * a + f(x % l, l);
        if (u <= y) a = Math.min(a, b + f(u - x, u - 1));
        return a;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        long n = in.nextLong();
         out.println(f(n, 111111111111111L));
    }
}
