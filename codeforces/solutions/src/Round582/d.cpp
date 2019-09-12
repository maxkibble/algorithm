#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int tmp = a[i];
    while (tmp) {
      tmp >>= 1;
      ans++;
    }
  }
  for (int i = 1; i <= a[n - 1]; i++) {
    int x = i, y = 1, t = 0, sum = k;
    long long can = 0;
    while (x <= a[n - 1]) {
      y--;
      int num = lower_bound(a.begin(), a.end(), x + y + 1) - 
        lower_bound(a.begin(), a.end(), x);
      num = min(num, sum);
      sum -= num;
      can += num * t;
      if (sum == 0) break;
      x <<= 1;
      y++;
      y <<= 1;
      t++;
    }
    if (sum == 0) ans = min(ans, can);
  }
  cout << ans << "\n";
  return 0;
}
