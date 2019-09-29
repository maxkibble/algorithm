/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.16 09:09:18
*   PROBLEM: HackerRank is-fibo
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;

const ll inf = 1e10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  vector<ll> fibs;
  fibs.pb(0);
  fibs.pb(1);
  int sz = 2;
  ll x = 1;
  while (x <= inf) {
    fibs.pb(x);
    sz++;
    x = fibs[sz - 1] + fibs[sz - 2];
  }
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    auto it = lower_bound(fibs.begin(), fibs.end(), n);
    if (it == fibs.end() || *it > n) cout << "IsNotFibo\n";
    else cout << "IsFibo\n";
  }
  return 0;
}
