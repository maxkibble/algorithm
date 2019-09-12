package KotlinHero_Practice2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.PrintWriter;

public class TaskG {

    class Point {
        int x, b;
        public Point(int xx, int bb) {
            x = xx;
            b = bb;
        }
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt(), l = in.nextInt();
        List<Point> ps = new ArrayList<>();
        ps.add(new Point(0, 0));
        for (int i = 1; i <= n; i++) {
            int x = in.nextInt(), b = in.nextInt();
            ps.add(new Point(x, b));
        }

        double[] dp = new double[1001];
        int[] pre = new int[1001];

        double lo = 0.0, hi = 1e7;
        for (int i = 0; i < 50; i++) {
            double mid = (lo + hi) / 2;
            for (int j = 1; j <= n; j++) {
                dp[j] = 1e18;
                for (int k = 0; k < j; k++) {
                    double can = dp[k] + Math.sqrt(Math.abs(ps.get(j).x - ps.get(k).x - l));
                    if (can < dp[j]) {
                        dp[j] = can;
                        pre[j] = k;
                    }
                }
                dp[j] -= ps.get(j).b * mid;
            }
            if (dp[n] <= 0) {
                hi = mid;
            } else lo = mid;
        }

        List<Integer> ans = new ArrayList<>();
        int ele = n;
        while (ele != 0) {
            ans.add(ele);
            ele = pre[ele];
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            out.print(ans.get(i) + " ");
        }
    }
}
