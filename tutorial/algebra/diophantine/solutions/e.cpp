/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.09 19:47:19
*   PROBLEM: LighOJ 1306
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll ret = ex_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - a / b * y1;
  return ret;
}

ll shift(ll s, ll t, ll step, bool greater) {
  // assert(step != 0);
  if (step < 0) step = -step;
  if ((t - s) % step == 0) return t;
  int sig = ((t - s) < 0)? -1: 1;
  ll ans;
  if (greater) {
    if (sig == 1) ans = ((t - s) / step + sig) * step + s;
    else ans = (t - s) / step * step + s;
  } else {
    if (sig == 1) ans = (t - s) / step * step + s;
    else ans = ((t - s) / step + sig) * step + s;
  }
  return ans;
}

ll find_all_solutions(ll a, ll b, ll c, ll x1, ll x2, ll y1, ll y2) {
  // a = 0 && b = 0
  if (a == 0 && b == 0) {
    if (c != 0) return 0;
    else return (x2 - x1 + 1) * (y2 - y1 + 1);
  }
  // a * b = 0
  if (a == 0) {
    if (c % b != 0) return 0;
    else {
      ll y = c / b;
      if (y >= y1 && y <= y2) return (x2 - x1 + 1);
      else return 0;
    }
  }
  if (b == 0) {
    if (c % a != 0) return 0;
    else {
      ll x = c / a;
      if (x >= x1 && x <= x2) return (y2 - y1 + 1);
      else return 0;
    }
  }
  // a * b != 0
  ll x, y;
  ll g = ex_gcd(abs(a), abs(b), x, y);
  if (c % g != 0) return 0;
  if (a < 0) x = -x;
  if (b < 0) y = -y;
  x = c / g * x;
  y = c / g * y;
  // assert(a * x + b * y == c);
  ll dx = abs(b / g), dy = abs(a / g);
  ll lx1 = shift(x, x1, dx, true);
  ll rx1 = shift(x, x2, dx, false);
  ll ly = shift(y, y1, dy, true);
  ll ry = shift(y, y2, dy, false);
  if (ly > ry) return 0;
  ll lx2 = (c - ly * b) / a;
  ll rx2 = (c - ry * b) / a;
  if (lx2 > rx2) swap(lx2, rx2);
  ll lx = max(lx1, lx2), rx = min(rx1, rx2);
  if (lx > rx) return 0;
  else return (rx - lx) / dx + 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    ll a, b, c, x1, x2, y1, y2;
    scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x1, &x2, &y1, &y2);
    c = -c;
    printf("Case %d: %lld\n", i, find_all_solutions(a, b, c, x1, x2, y1, y2));
  }
  return 0;
}
