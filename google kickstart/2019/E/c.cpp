/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.08.30 10:59:07
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e9 + 5;

vector<int> pr;
bitset<maxn> f(0);

void pre_process() {
  for (int i = 2; i < maxn; i++) {
    if (f.test(i)) continue;
    pr.push_back(i);
    for (int j = i + i; j < maxn; j += i) f[j] = 1;
  }
}

bool is_prime(int x) {
  if (x == 1) return true;
  auto it = lower_bound(pr.begin(), pr.end(), x);
  if (it == pr.end()) return false;
  if (*it == x) return true;
  else return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  pre_process();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int l, r, ans = 0;
    cin >> l >> r;
    for (int j = l; j <= r; j++) {
      if (j % 2 == 0 && j % 4 != 0) ans++;
      else if (j % 4 == 0) {
        if (is_prime(j / 4)) ans++;
      } else {
        if (is_prime(j)) ans++;
      }
    }
    cout << "Case #" << i << ": " << ans << "\n";
  }
  return 0;
}
