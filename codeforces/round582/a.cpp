#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, odd = 0, even = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) even++;
    else odd++;
  }
  cout << min(odd, even) << "\n";
  return 0;
}
