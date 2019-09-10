/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.08 01:49:25
*   PROBLEM: UVA 11029
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
    int n, k;
    cin >> n >> k;
    double a = k * log10(n);
    int ans1 = pow(10, a - floor(a)) * 100;
    ll ans2 = 1;
    while (k) {
      if (k & 1) ans2 = ans2 * n % 1000;
      n = n * 1ll * n % 1000;
      k >>= 1;
    }
    cout << ans1 << "..." << setw(3) << setfill('0') << ans2 << endl;
  }
  return 0;
}
