#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  for (int i = 0; i < n; i++) {
    int smaller = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] < a[i]) smaller++;
    }
    if (smaller == 1) {
      cout << a[i] << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
