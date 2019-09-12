#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      b[i] = min(a[i], b[i + 1]);
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > b[i + 1]) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
