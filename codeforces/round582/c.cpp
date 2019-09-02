#include <bits/stdc++.h>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    long long n, m, ans = 0;
    cin >> n >> m;
    long long t = m * 10 / gcd(m, 10);
    for (long long i = m; i < t; i += m) {
      ans += i % 10;
    }
    ans *= n / t;
    for (long long i = m; i <= n % t; i += m) {
      ans += i % 10;
    }
    cout << ans << "\n";
  }
  return 0;
}
