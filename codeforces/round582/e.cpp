#include <bits/stdc++.h>

using namespace std;

int n;
string s, t;

bool f;
vector<bool> used(3);
string ans;

bool check(string x) {
  assert(x.length() == 3);
  if (n == 1) {
    for (int i = 0; i < 2; i++) {
      string y = x.substr(i, 2);
      if (y == s || y == t) return false;
    }
    return true;
  }
  x = x + x;
  for (int i = 0; i < 3; i++) {
    string y = x.substr(i, 2);
    if (y == s || y == t) return false;
  }
  return true;
}

void dfs(int x, string y) {
  if (f) return;
  if (x == 3) {
    if (check(y)) {
      f = true;
      for (int i = 0; i < n; i++) ans += y;
    }
    return;
  }
  for (int i = 0; i < 3; i++) {
    if (used[i]) continue;
    used[i] = true;
    y.push_back('a' + i);
    dfs(x + 1, y);
    y.pop_back();
    used[i] = false;
  }
}

int main() {
  cout << "YES\n";
  cin >> n >> s >> t;
  if (s == t && s[0] != s[1]) {
    for (int i = 0; i < n; i++) {
      ans.push_back(s[1]);
      ans.push_back(s[0]);
      ans.push_back(3 - (s[0] - 'a') - (s[1] - 'a') + 'a');
    }
    cout << ans << "\n";
    return 0;
  }
  if (s[0] != s[1] && s[0] == t[1] && s[1] == t[0]) {
    for (int i = 0; i < n; i++) ans.push_back(s[0]);
    for (int i = 0; i < n; i++) ans.push_back(3 - (s[0] - 'a') - (s[1] - 'a') + 'a');
    for (int i = 0; i < n; i++) ans.push_back(s[1]);
    cout << ans << "\n";
    return 0;
  }
  if (s[0] == t[0] && s[1] != s[0] && t[1] != t[0]) {
    for (int i = 0; i < n; i++) {
      ans.push_back(s[1]);
      ans.push_back(t[1]);
    }
    for (int i = 0; i < n; i++) ans.push_back(s[0]);
    cout << ans << "\n";
    return 0;
  }
  if (s[1] == t[1] && s[0] != s[1] && t[0] != t[1]) {
    for (int i = 0; i < n; i++) {
      ans.push_back(s[1]);
    }
    for (int i = 0; i < n; i++) {
      ans.push_back(s[0]);
      ans.push_back(t[0]);
    }
    cout << ans << "\n";
    return 0;
  }
  dfs(0, "");
  cout << ans << "\n";
  return 0;
}
