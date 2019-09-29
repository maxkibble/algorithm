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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 0) {
    cout << s << "\n";
    return 0;
  }
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  if (s[0] != '1') {
    s[0] = '1';
    k--;
  }
  for (int i = 1; i < s.length() && k > 0; i++) {
    if (s[i] != '0') {
      s[i] = '0';
      k--;
    }
  }
  cout << s << "\n";
  return 0;
}
