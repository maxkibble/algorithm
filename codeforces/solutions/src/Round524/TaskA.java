package CF524;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskA {
  public int f(int x, int y) {
    return x % y != 0? x / y + 1: x / y;
  }

  public void solve(int testNumber, Scanner in, PrintWriter out) {
    int n = in.nextInt(), k = in.nextInt();
    int ans = f(2 * n, k) + f(5 * n, k) + f(8 * n, k);
    out.print(ans);
  }
}
