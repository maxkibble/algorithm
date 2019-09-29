/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.07 18:14:24
*   PROBLEM: SPOJ CEQU
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    bool ans;
    if (c % gcd(a, b) == 0) ans = true;
    else ans = false;
    cout << "Case " << i << ": " << (ans? "Yes": "No") << "\n";
  }
  return 0;
}
