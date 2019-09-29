package KotlinHero_Episode2;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskD {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt(), a = in.nextInt(), b = in.nextInt(), k = in.nextInt();
        final int maxR = 1000005;
        int[] cnt = new int[maxR];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            cnt[x]++;
        }
        int ans = 0;
        if (a < b) {
            for (int i = maxR - 1; i >= 1; i--) {
                if (i % k != 0) continue;
                int j = i / k;
                int numA = cnt[j] / a;
                int numB = cnt[i] / b;
                int num = Math.min(numA, numB);
                cnt[j] -= num * a;
                cnt[i] -= num * b;
                ans += num;
            }
        } else {
            for (int i = 1; i < maxR; i++) {
                if (i * k >= maxR) break;
                int j = i * k;
                int numA = cnt[i] / a;
                int numB = cnt[j] / b;
                int num = Math.min(numA, numB);
                cnt[i] -= num * a;
                cnt[j] -= num * b;
                ans += num;
            }
        }
        out.println(ans);
    }
}

// 1*2 2*4 4*8 a=1 b=2 k=2
// sol 1: (1,2,2)*2
// sol 2: (2,4,4)*4