/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.07 22:48:56
*   PROBLEM: UVA 1230
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
  int t;
  cin >> t;
  while (t--) {
    long long x, y, n;
    cin >> x >> y >> n;
    long long ans = 1;
    while (y) {
      if (y & 1) ans = ans * x % n;
      x = x * x % n;
      y >>= 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
