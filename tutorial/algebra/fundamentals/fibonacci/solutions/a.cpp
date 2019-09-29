/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.14 00:15:26
*   PROBELM: SPOJ MAIN74
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;

const ll mod = 1000000007;

pair<ll, ll> fib (ll n) {
  if (n == 0)
    return {0, 1};
  auto p = fib(n >> 1);
  ll c = p.first * 1ll * ((2 * p.second - p.first + mod) % mod) % mod;
  ll d = (p.first * 1ll * p.first % mod + p.second * 1ll * p.second % mod) % mod;
  if (n & 1)
    return {d, (c + d) % mod};
  else
    return {c, d};
}

int main() {
  // freopen("a.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n;
    scanf("%lld\n", &n);
    if (n == 0) {
      printf("0\n");
      continue;
    }
    if (n != 1) n++;
    pair<ll, ll> fib_n = fib(n);
    printf("%lld\n", (fib_n.fi + fib_n.se) % mod);
  }
  return 0;
}
