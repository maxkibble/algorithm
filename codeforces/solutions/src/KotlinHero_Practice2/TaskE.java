package KotlinHero_Practice2;

import java.util.*;
import java.io.PrintWriter;

public class TaskE {

    class Request implements Comparable<Request> {
        int c, p, i;
        public Request(int cc, int pp, int ii) {
            c = cc;
            p = pp;
            i = ii;
        }
        public int compareTo(Request rhs) {
            return rhs.p - p;
        }
    }

    class Table implements Comparable<Table> {
        int r, i;
        public Table(int rr, int ii) {
            r = rr;
            i = ii;
        }
        public int compareTo(Table rhs) {
            return r - rhs.r;
        }
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        List<Request> rs = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int c = in.nextInt(), p = in.nextInt();
            rs.add(new Request(c, p, i));
        }
        Collections.sort(rs);

        int k = in.nextInt();
        List<Table> ts = new ArrayList<>();
        for (int i = 1; i <= k; i++) {
            int r = in.nextInt();
            ts.add(new Table(r, i));
        }
        Collections.sort(ts);

        int tot = 0;
        List<Integer> rid = new ArrayList<>(),
                tid = new ArrayList<>();
        for (Request r: rs) {
            if (ts.isEmpty()) break;
            int idx = Collections.binarySearch(ts, new Table(r.c, 0));
            if (idx < 0) idx = -idx - 1;
            if (idx == ts.size()) continue;
            tot += r.p;
            rid.add(r.i);
            tid.add(ts.get(idx).i);
            ts.remove(idx);
        }

        out.println(rid.size() + " " + tot);
        for (int i = 0; i < rid.size(); i++) {
            out.println(rid.get(i) + " " + tid.get(i));
        }
    }
}
