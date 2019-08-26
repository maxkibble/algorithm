/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.08.26 16:12:45
*   PROBLEM: CODEFORCES 630I
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

long long binpow(long long a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n;
  m = 2 * n - 2;
  long long ans = 2 * 3 * binpow(4, m - n - 1);
  for (int i = 1; i + n < m; i++) {
    ans += 3 * 3 * binpow(4, m - n - 2);
  }
  cout << ans * 4 << "\n";
  return 0;
}
