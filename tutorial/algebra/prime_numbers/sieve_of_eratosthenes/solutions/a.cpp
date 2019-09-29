/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.18 19:36:15
*   PROBELM: https://codeforces.com/contest/26/problem/A
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
  int n;
  cin >> n;
  vector<int> seive(n + 1, 0);
  seive[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (seive[i] != 0) continue;
    for (int j = i; j <= n; j += i) {
      seive[j] += 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (seive[i] == 2) ans++;
  }
  cout << ans << "\n";
  return 0;
}
