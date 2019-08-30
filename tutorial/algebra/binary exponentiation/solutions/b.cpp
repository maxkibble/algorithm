/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.08.27 18:17:04
*   PROBLEM: SPOJ LASTDIG
*
=====================================*/


#include <iostream>

using namespace std;

long long binpow(long long a, long long b, long long m) {
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
  int k;
  cin >> k;
  while (k--) {
    long long a, b;
    cin >> a >> b;
    cout << binpow(a, b, 10) << "\n";
  }
  return 0;
}
