package KotlinHero_Practice2;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.PrintWriter;

public class TaskC {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt(), k = in.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x;
            x = in.nextInt();
            a.add(x);
        }
        a.sort(Integer::compareTo);
        int ans;
        if (k == n) {
            ans = a.get(n - 1);
        } else if (k == 0) {
            if (a.get(0) == 1) ans = -1;
            else ans = a.get(0) - 1;
        }
        else {
            if (a.get(k - 1) == a.get(k)) ans = -1;
            else ans = a.get(k - 1);
        }
        out.println(ans);
    }
}
