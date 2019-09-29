#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 3e5 + 5;
const ll inf = 1e18 + 5;

int q, n;
int a[maxn], b[maxn];
ll dp[3][maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    a[0] = -100;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        dp[j][i] = inf;
        for (int k = 0; k < 3; k++) {
          if (a[i] + j != a[i - 1] + k) {
            dp[j][i] = min(dp[j][i], dp[k][i - 1] + j * 1ll * b[i]);
          }
        }
      }
    }
    cout << min(min(dp[0][n], dp[1][n]), dp[2][n]) << "\n";
  }
  return 0;
}
