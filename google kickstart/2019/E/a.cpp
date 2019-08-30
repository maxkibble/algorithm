/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.08.29 17:04:13
*
=====================================*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;
int cnt, tot, color[maxn];
vector<int> g[maxn];

void dfs(int cur) {
  color[cur] = cnt;
  tot++;
  for (int nxt: g[cur]) {
    if (!color[nxt]) dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n >> m;
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
    cnt = 0, tot = 0;
    for (int j = 0; j < m; j++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int j = 1; j <= n; j++) {
      if (color[j]) continue;
      cnt++;
      dfs(j);
    }
    cout << "Case #" << i << ": " << tot - cnt + (n - 1 - tot + cnt) * 2 << "\n";
  }
  return 0;
}
