/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.05 22:15:13
*   PROBLEM: UVA 12775
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a, int b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - a / b * y1;
  return d;
}

int solve(int a, int b, int p) {
  long long x, y;
  int g = gcd(a, b, x, y);
  if (p % g != 0) return 0;
  // x * a + y * b = p
  x = x * (p / g);
  y = y * (p / g);
  long long l = a / g * 1ll * b;
  int ua = l / a, ub = l / b;
  int st = (x % ua + ua) % ua;
  int ed = (p - (y % ub + ub) % ub * b) / a;
  if (ed < st) return 0;
  else return (ed - st) / ua + 1;
}

int main() {
  // freopen("input", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a, b, c, p;
    long long ans = 0;
    cin >> a >> b >> c >> p;
    for (int j = 0; j <= p / c; j++) {
      ans += solve(a, b, p - j * c);
    }
    cout << "Case " << i << ": " << ans << "\n";
  }
  return 0;
}
