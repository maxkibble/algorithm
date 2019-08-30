/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.08.27 19:32:45
*   PROBLEM: SPOJ ZSUM
*
=====================================*/

#include <iostream>

using namespace std;

const int m = 1e7 + 7;

long long binpow(long long a, long long b) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  long long n, k;
  while (cin >> n >> k) {
    if (n == 0) break;
    long long ans = binpow(n - 1, k) * 2 % m;
    ans = (ans + binpow(n, k)) % m;
    ans = (ans + binpow(n - 1, n - 1) * 2 % m) % m;
    ans = (ans + binpow(n, n)) % m;
    cout << ans << "\n";
  }
  return 0;
}
