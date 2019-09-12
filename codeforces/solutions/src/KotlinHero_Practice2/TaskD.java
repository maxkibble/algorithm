package KotlinHero_Practice2;

import kotlin.Pair;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.io.PrintWriter;

public class TaskD {

    class Pair {
        long x;
        int y;
        Pair(long xx, int yy) {
            x = xx;
            y = yy;
        }
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        List<Long> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            long x = in.nextLong();
            a.add(x);
        }
        int maxThree = 0;
        List<ArrayList<Pair>> b = new ArrayList<>();
        for (int i = 0; i < 55; i++) b.add(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            int two = 0, three = 0;
            long x = a.get(i);
            while (x % 2 == 0) {
                two++;
                x /= 2;
            }
            while (x % 3 == 0) {
                three++;
                x /= 3;
            }
            maxThree = Math.max(three, maxThree);
            Pair item = new Pair(a.get(i), two);
            b.get(three).add(item);
        }
        for (int i = maxThree; i >= 0; i--) {
            b.get(i).sort(Comparator.comparingInt(p -> p.y));
            for (Pair p: b.get(i)) out.print(p.x + " ");
        }
    }
}
