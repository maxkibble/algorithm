#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, k;
int a[maxn], b[maxn];
int fa[maxn];

int get_fa(int x) {
  return fa[x] == x? x: (fa[x] = get_fa(fa[x]));
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  // dsu
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    int f1 = get_fa(a[i]), f2 = get_fa(b[i]);
    if (f1 == f2) continue;
    fa[f2] = f1;
  }

  vector<int> clusters[maxn];
  vector<int> cluster_sz(maxn);
  for (int i = 1; i <= n; i++) {
    int j = get_fa(i);
    clusters[j].push_back(i);
    cluster_sz[j]++;
  }

  set<int> S;
  char c = 'a';
  string ans;
  ans.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    ans[a[i]] = c;
    int j = fa[a[i]];
    cluster_sz[j]--;
    if (S.count(j) == 0 && cluster_sz[j] > 0) {
      S.insert(j);
    }
    if (S.count(j) > 0 && cluster_sz[j] == 0) {
      S.erase(j);
    }
    if (S.empty() && c < 'z') c++;
  }

  ans = ans.substr(1);
  set<char> ss;
  for (char ch: ans) ss.insert(ch);
  if (ss.size() < k) cout << "NO\n";
  else cout << "YES\n" << ans << "\n";
    
  return 0;
}
