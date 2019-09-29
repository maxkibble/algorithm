#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 105;

int n;
char ans[maxn][maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) ans[i][j] = 'W';
      else ans[i][j] = 'B';
      cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}
