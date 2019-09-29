/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.19 10:54:09
*   PRBLEM: CODEFORCES 17A
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
  int n, k;
  cin >> n >> k;
  vector<int> primes;
  vector<bool> is_prime(n + 1, true);
  for (int i = 2; i * i <= n; i++) {
    if (!is_prime[i]) continue;
    for (int j = i + i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) primes.pb(i);
  }
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (!is_prime[i]) continue;
    int s = i - 1;
    auto p1 = upper_bound(primes.begin(), primes.end(), s >> 1);
    if (p1 == primes.end()) continue;
    int id1 = p1 - primes.begin();
    auto p2 = lower_bound(primes.begin(), primes.end(), s - *p1);
    int id2 = p2 - primes.begin();
    if (*p1 + *p2 == s && id1 - 1 == id2) {
      ans++;
      // cout << s << " " << *p1 << " " << *p2 << "\n";
    }
  }
  cout << (ans >= k? "YES": "NO");
  return 0;
}
