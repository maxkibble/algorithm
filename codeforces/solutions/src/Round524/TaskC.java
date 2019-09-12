package CF524;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskC {

  public long countBlack(long x1, long y1, long x2, long y2) {
    if (x2 < x1 || y2 < y1) return 0;
    long area = (x2 - x1 + 1) * (y2 - y1 + 1);
    if ((x2 - x1) % 2 == 0 && (y2 - y1) % 2 == 0 && (x1 + y2) % 2 == 1) {
      return area / 2 + 1;
    } else return area / 2;
  }

  public long merge(long x1, long y1, long x2, long y2,
                    long x3, long y3, long x4, long y4) {
    long x5 = Math.max(x1, x3), y5 = Math.max(y1, y3);
    long x6 = Math.min(x2, x4), y6 = Math.min(y2, y4);
    // System.out.println("Merge: " + x5 + "," + y5 + "," + x6 + "," + y6);
    return countBlack(x5, y5, x6, y6);
  }

  public void solve(int testNumber, Scanner in, PrintWriter out) {
    int q = in.nextInt();
    while (q != 0) {
      q--;
      long n = in.nextLong(), m = in.nextLong();
      long b = countBlack(1, 1, n, m);
      long w = n * m - b;
      long x1 = in.nextLong(), y1 = in.nextLong(), x2 = in.nextLong(), y2 = in.nextLong();
      long x3 = in.nextLong(), y3 = in.nextLong(), x4 = in.nextLong(), y4 = in.nextLong();
      long b1 = countBlack(x1, y1, x2, y2);
      b -= b1;
      w += b1;
      long w1 = (x4 - x3 + 1) * (y4 - y3 + 1) - countBlack(x3, y3, x4, y4);
      b += w1;
      w -= w1;
      long both = merge(x1, y1, x2, y2, x3, y3, x4, y4);
      b += both;
      w -= both;
      out.println(w + " " + b);
    }
  }
}
