#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int n, m, ans;
vector<int> g[10];
vector<int> f(10);

int check() {
  int ret = 0;
  int used[7][7] = {0};
  for (int i = 1; i <= n; i++) {
    for (int j: g[i]) {
      int fi = f[i], fj = f[j];
      if (fi > fj) swap(fi, fj);
      if (used[fi][fj]) continue;
      else {
        ret++;
        used[fi][fj] = 1;
      }
    }
  }
  return ret;
}

void dfs(int x) {
  if (x == n + 1) {
    ans = max(ans, check());
    return;
  }
  for (int i = 1; i <= 6; i++) {
    f[x] = i;
    dfs(x + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  cout << ans << "\n";
  return 0;
}
