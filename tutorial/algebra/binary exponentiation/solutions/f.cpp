/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.07 22:53:56
*   PROBLEM: UVA 374
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  ll b, p, m;
  while (cin >> b >> p >> m) {
    ll ans = 1;
    while (p) {
      if (p & 1) ans = ans * b % m;
      b = b * b % m;
      p >>= 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
