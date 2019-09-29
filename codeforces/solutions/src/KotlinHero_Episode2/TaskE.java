package KotlinHero_Episode2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.PrintWriter;

public class TaskE {

    final int maxn = 200005;
    int n, lo = 0, hi = 0;
    int[] a = new int[maxn];

    private boolean check(int x) {
        List<Integer> p = new ArrayList<>();
        int y = 0;
        int[] cc = new int[x + 1];
        for (int i = 0; i < n; i++) {
            int ai = a[i];
            if (ai > x) continue;
            if (cc[ai] == 0) {
                p.add(ai);
            } else {
                if (p.get(y) != ai) {
                    return false;
                }
                y++;
            }
            cc[ai]++;
        }
        return true;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        n = in.nextInt();
        int[] c = new int[maxn];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            c[a[i]]++;
        }
        for (int i = 1; i < maxn; i++) {
            if (c[i] != 2) break;
            hi++;
        }
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check(mid)) lo = mid;
            else hi = mid - 1;
        }
        StringBuilder sb = new StringBuilder();
        int[] cc = new int[100005];
        for (int i = 0; i < n; i++) {
            if (a[i] > lo) {
                sb.append('B');
                continue;
            }
            if (cc[a[i]] == 0) sb.append('R');
            else sb.append('G');
            cc[a[i]]++;
        }
        out.println(sb);
    }
}
