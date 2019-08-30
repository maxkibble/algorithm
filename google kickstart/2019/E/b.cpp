/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.08.29 20:55:25
*
=====================================*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Slot {
  int c, e;
  bool operator < (const Slot &obj) const {
    return e * obj.c > c * obj.e;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int d, s;
    cin >> d >> s;
    vector<Slot> slots(s + 1);
    for (int j = 1; j <= s; j++) {
      cin >> slots[j].c >> slots[j].e;
    }
    sort(slots.begin() + 1, slots.end());
    vector<int> to_cost(s + 1), to_add(s + 1);
    for (int j = 1; j <= s; j++) {
      to_cost[j] = to_cost[j - 1] + slots[j].c;
      to_add[j] = to_add[j - 1] + slots[j].e;
    }
    string ans = "";
    while (d--) {
      int a, b;
      cin >> a >> b;
      if (a > to_cost[s] || b > to_add[s]) {
        ans.push_back('N');
        continue;
      }
      int idx = lower_bound(to_add.begin(), to_add.end(), b) - to_add.begin();
      int aa = a - (to_cost[s] - to_cost[idx]);
      int bb = to_add[idx] - b;
      if (aa * 1ll * slots[idx].e <= bb * 1ll * slots[idx].c) ans.push_back('Y');
      else ans.push_back('N');
    }
    cout << "Case #" << i << ": " << ans << "\n";
  }
  return 0;
}
