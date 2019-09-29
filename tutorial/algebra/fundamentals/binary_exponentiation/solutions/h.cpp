/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.08 15:39:59
*   PROBELM: UVALive 3722
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

ll mypow(ll a, ll n, ll c) {
  ll ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % c;
    a = a * a % c;
    n >>= 1;
  }
  return ans;
}

ll sum(ll a, ll n, ll c) {
  if (n == 1) {
    return a % c;
  }
  ll k = mypow(a, n >> 1, c);
  ll s = sum(a, n >> 1, c);
  ll ret = (s + k * s % c) % c;
  if (n & 1) ret = (ret + mypow(a, n, c)) % c;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  ll x, a, n, c;
  while (cin >> x >> a >> n >> c) {
    if (x == 0) break;
    ll an = mypow(a, n, c);
    ll ans = an * x % c - sum(a, n, c);
    ans = (ans % c + c) % c;
    cout << ans << "\n";
  }
  return 0;
}
