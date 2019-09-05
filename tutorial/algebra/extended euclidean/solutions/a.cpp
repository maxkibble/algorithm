/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.04 20:12:30
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int gcd(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd(b % a, a, x1, y1);
  x = y1 - b / a * x1;
  y = x1;
  return d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int a, b, x, y;
  while (cin >> a >> b) {
    if (a == b) {
      cout << "0 1 " << a << "\n";
      continue;
    }
    int d = gcd(a, b, x, y);
    cout << x << " " << y << " " << d << "\n";
  }
  return 0;
}
