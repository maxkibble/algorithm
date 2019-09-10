/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.07 18:32:07
*   PROBLEM: SGU 106
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

ll myabs(ll a) {
  return a < 0? -a: a;
}

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = ex_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - a / b * y1;
  return d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  ll a, b, c, x1, x2, y1, y2;
  cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
  c = -c;

  // a = b = 0
  if (a == 0 && b == 0) {
    if (c == 0) {
      cout << (x2 - x1 + 1) * 1ll * (y2 - y1 + 1) << "\n";
    } else cout << "0\n";
    return 0;
  }

  // a = 0 || b = 0
  if (a == 0) {
    if (c % b != 0) cout << "0\n";
    else {
      ll y = c / b;
      if (y >= y1 && y <= y2) {
        cout << x2 - x1 + 1 << "\n";
      } else cout << "0\n";
    }
    return 0;
  } else if (b == 0) {
    if (c % a != 0) cout << "0\n";
    else {
      ll x = c / a;
      if (x >= x1 && x <= x2) {
        cout << y2 - y1 + 1 << "\n";
      } else cout << "0\n";
    }
    return 0;
  }

  // a != 0 && b != 0
  ll x, y;
  ll g = ex_gcd(myabs(a), myabs(b), x, y);
  if (a < 0) x = -x;
  if (b < 0) y = -y;
  if (c % g != 0) {
    cout << "0\n";
    return 0;
  }
  x = c / g * x;
  y = c / g * y;

  // a * x + b * y = c 
  assert(a * x + b * y == c);

  auto shift = [](ll s, ll t, ll step, bool greater) {
    if ((t - s) % step == 0) return t;
    int sig = (t - s < 0)? -1: 1;
    long long ret;
    if (greater) {
      if (sig == 1) ret = step * ((t - s) / step + sig) + s;
      else ret = step * ((t - s) / step) + s;
    } else {
      if (sig == 1) ret = step * ((t - s) / step) + s;
      else ret = step * ((t - s) / step + sig) + s;
    }
    return ret;
  };

  ll dx = myabs(b / g), dy = myabs(a / g);
  ll Lx[2], Rx[2], Ly, Ry;
  Lx[0] = shift(x, x1, dx, true);
  Rx[0] = shift(x, x2, dx, false);
  Ly = shift(y, y1, dy, true); 
  Ry = shift(y, y2, dy, false);
  if (Ly > Ry) {
    cout << "0\n";
    return 0;
  }
  ll lx = (c - Ly * b) / a, rx = (c - Ry * b) / a;
  if (lx > rx) swap(lx, rx);
  Lx[1] = lx, Rx[1] = rx;

  ll LX = max(Lx[0], Lx[1]), RX = min(Rx[0], Rx[1]);
  if (RX < LX) cout << "0\n";
  else cout << (RX - LX) / dx + 1 << "\n";

  return 0;
}
