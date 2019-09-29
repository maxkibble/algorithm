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
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int l = 0;
    vector<int> a;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '.') l++;
      else if (l != 0) {
        a.pb(l);
        l = 0;
      }
    }
    if (l != 0) a.pb(l);

    vector<int> b(3);

    auto judge = [&b]() {
      if (b[0] > 0 || b[2] > 0) return false;
      return (b[1] % 2 == 0);
    };

    auto add = [&b, &x, &y](int ai, int d) {
      if (ai < y) return;
      if (ai >= y && ai < x) b[0] += d;
      else if (ai >= x && ai < 2 * y) b[1] += d;
      else b[2] += d; 
    };

    bool ans = true; // bob win

    for (auto ai: a) {
      add(ai, 1);
    }

    for (auto ai: a) {
      if (ai < x) continue;
      if (ai < 2 * y) b[1]--;
      else b[2]--;
      for (int i = 0; i <= ai - x; i++) {
        add(i, 1);
        add(ai - x - i, 1);
        if (judge()) {
          ans = false;
          break;
        }
        add(i, -1);
        add(ai - x - i, -1);
      }
      if (ai < 2 * y) b[1]++;
      else b[2]++;
      if (!ans) break;
    }

    cout << (ans? "NO\n": "YES\n");
  }
  return 0;
}
