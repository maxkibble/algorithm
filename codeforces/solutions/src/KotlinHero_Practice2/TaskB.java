package KotlinHero_Practice2;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.io.PrintWriter;

public class TaskB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        String s = in.next();
        Map<String, Integer> m = new HashMap<>();
        String ans = "";
        int ans_x = 0;
        for (int i = 0; i < n - 1; i++) {
            String ss = s.substring(i, i + 2);
            int x = m.getOrDefault(ss, 0);
            m.put(ss, x + 1);
            if (x + 1 > ans_x) {
                ans = ss;
                ans_x = x + 1;
            }
        }
        out.println(ans);
    }
}
