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
  while (q--) {
    int c, m, x;
    cin >> c >> m >> x;
    cout << min(min(c, m), (c + m + x) / 3) << "\n";
  }
  return 0;
}
