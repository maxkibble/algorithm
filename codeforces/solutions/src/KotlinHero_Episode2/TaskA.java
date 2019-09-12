package KotlinHero_Episode2;

import java.util.*;
import java.io.PrintWriter;

class MyPair implements Comparable<MyPair> {
    int fi, se;
    MyPair(int x, int y) {
        fi = x;
        se = y;
    }

    @Override
    public int compareTo(MyPair o) {
        return fi - o.fi;
    }
}

public class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        Set<MyPair> st = new TreeSet<>();
        for (int i = 1; i <= n; i++) {
            st.add(new MyPair(in.nextInt(), i));
        }
        if (st.size() >= 3) {
            int cnt = 0;
            Iterator<MyPair> it = st.iterator();
            while (cnt < 3 && it.hasNext()) {
                MyPair p = it.next();
                out.print(p.se + " ");
                cnt++;
            }
        } else out.println("-1 -1 -1");
    }
}
