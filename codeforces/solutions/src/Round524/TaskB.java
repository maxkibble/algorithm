package CF524;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskB {

  public int f(int x) {
    if (x % 2 == 0) {
      return x / 2;
    } else {
      return (x - 1) / 2 - x;
    }
  }

  public void solve(int testNumber, Scanner in, PrintWriter out) {
    int q = in.nextInt();
    while (q != 0) {
      q--;
      int l = in.nextInt(), r = in.nextInt();
      out.println(f(r) - f(l - 1));
    }
  }
}
