package KotlinHero_Episode2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.io.PrintWriter;

class Item implements Comparable<Item> {
    long a, b, c;

    Item(int x, int y, int z) {
        a = x;
        b = y;
        c = z;
    }

    @Override
    public int compareTo(Item o) {
        return c - o.c < 0? -1: 1;
    }
}

public class TaskC {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        long k = in.nextLong();
        List<Item> items = new ArrayList<>();
        long sa = 0, sb = 0;
        for (int i = 0; i < n; i++) {
            int x = in.nextInt(), y = in.nextInt(), z = in.nextInt();
            sa += x;
            sb += y;
            items.add(new Item(x, y, z));
        }
        if (sa > k || sb < k) {
            out.println(-1);
            return;
        }
        k -= sa;
        long ans = 0;
        Collections.sort(items);
        for (Item item: items) {
            long d = Math.min(k, item.b - item.a);
            ans += (item.a + d) * item.c;
            k -= d;
        }
        out.println(ans);
    }
}
