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
  int a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a, a + 4);
  if (a[0] + a[3] == a[1] + a[2] || a[3] == a[0] + a[1] + a[2]) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
