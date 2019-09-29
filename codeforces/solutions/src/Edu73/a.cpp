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
  int q;
  cin >> q;
  auto f = [](int x) {
    int ret = 0;
    while (x > 1) {
      x = x / 2;
      ret++;
    }
    return ret;
  };
  while (q--) {
    int n;
    cin >> n;
    int a[15] = {0};
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > 2048) continue;
      a[f(x)]++;
    }
    for (int i = 0; i < 11; i++) {
      a[i + 1] += a[i] / 2;
      a[i] %= 2;
    }
    if (a[11] > 0) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
