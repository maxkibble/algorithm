/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.09 18:18:30
*   PROBLEM: CodeChef COPR16G
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    if (g > 1) cout << "-1\n";
    else cout << (a - 1) * (b - 1) << "\n";
  }
  return 0;
}
