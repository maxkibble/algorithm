/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.07 22:58:01
*   PROBLEM: CODECHEF FLOW016
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
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    cout << g << " " << a / g * 1ll * b << "\n";
  }
  return 0;
}
