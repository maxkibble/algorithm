/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.08.27 18:29:36
*   PROBLEM: SPOJ LOCKER
*
=====================================*/


#include <iostream>

using namespace std;

const int m = 1e9 + 7;

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
  int t;
  cin >> t;
  while (t--) {
    long long a, ans;
    cin >> a;
    if (a == 1) {
      cout << "1\n";
      continue;
    }
    if (a % 3 == 1)
      ans = binpow(3, (a - 4) / 3) * 4 % m;
    else if (a % 3 == 2)
      ans = binpow(3, (a - 2) / 3) * 2 % m;
    else
      ans = binpow(3, a / 3);
    cout << ans << "\n";
  }
  return 0;
}
