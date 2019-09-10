/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.09 12:38:23
*   PROBLEM: CODEFORCES 633A
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - a / b * y1;
  return d;
}

ll shift(ll s, ll t, ll d, bool greater) {
  assert(d > 0);
  if ((t - s) % d == 0) return t;
  ll sig = (t - s < 0)? -1: 1;
  ll ans;
  if (greater) {
    if (sig == 1) ans = ((t - s) / d + 1) * d + s;
    else ans = (t - s) / d * d + s;
  } else {
    if (sig == 1) ans = (t - s) / d * d + s;
    else ans = ((t - s) / d - 1) * d + s;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  ll a, b, c;
  cin >> a >> b >> c;
  ll x, y;
  // a, b > 0
  ll g = gcd(a, b, x, y);
  if (c % g != 0) {
    cout << "NO\n";
    return 0;
  }
  x = c / g * x;
  y = c / g * y;
  ll dx = b / g;
  ll lx = shift(x, 0, dx, true);
  ll rx = shift(x, c / a, dx, false);
  if (rx >= lx) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
