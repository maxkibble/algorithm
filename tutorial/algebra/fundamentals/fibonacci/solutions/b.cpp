/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.14 10:19:57
*   PROBLEM: SPOJ FIBOSUM
*
=====================================*/


/*
 * 1 1 1     sum_{i-1}   sum_i
 * 0 1 1  X  fib_{i-1} = fib_i
 * 0 1 0     fib_{i-2}   fib_{i-1}
 *
 */

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

struct Matrix {
  int n, m, mod;
  vector<vector<ll>> A;
  
  Matrix(int a, int b, bool unit = false, int c = 1000000007) {
    n = a, m = b, mod = c;
    A.resize(n);
    for (int i = 0; i < n; i++) A[i].resize(m);
    if (unit) {
      for (int i = 0; i < n; i++) A[i][i] = 1;
    }
  }

  ll get(int i, int j) const {
    return A[i][j];
  }

  void set(int i, int j, ll val) {
    A[i][j] = val;
  }

  Matrix multi(const Matrix &rhs) const {
    assert(m == rhs.n);
    Matrix ret = Matrix(n, rhs.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < rhs.m; j++) {
        for (int k = 0; k < m; k++) {
          ll val = ret.get(i, j);
          val = (val + get(i, k) * rhs.get(k, j) % mod) % mod;
          ret.set(i, j, val);
        }
      }
    }
    return ret;
  }

  Matrix pow(ll x) const {
    assert(n == m);
    Matrix ret = Matrix(n, n, true);
    Matrix a = *this;
    while (x) {
      if (x & 1) ret = ret.multi(a);
      a = a.multi(a);
      x >>= 1;
    }
    return ret;
  }
  
  void print() const {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << get(i, j) << " ";
      cout << "\n";
    }
  }

};

Matrix a = Matrix(3, 3);
Matrix b = Matrix(3, 1);

int calc(int x) {
  if (x == -1) return 0;
  return a.pow(x).multi(b).get(0, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  a.set(0, 0, 1); a.set(0, 1, 1); a.set(0, 2, 1);
  a.set(1, 0, 0); a.set(1, 1, 1); a.set(1, 2, 1);
  a.set(2, 0, 0); a.set(2, 1, 1); a.set(2, 2, 0);
  b.set(0, 0, 0); b.set(1, 0, 0); b.set(2, 0, 1);

  const int mod = 1000000007;
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cout << (calc(m) - calc(n - 1) + mod) % mod << "\n";
  }
  return 0;
}
