/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.09.20 23:22:21
*
=====================================*/


#include <iostream>
#include <vector>

template<typename T>
struct SegTree {
  int n;
  std::vector<T> t;     // 1-index
  std::vector<T> lazy;  // 1-index

  SegTree(int nn): n(nn) {
    t.resize(4 * (nn + 1));
    lazy.resize(4 * (nn + 1));
  }

  // Simple pushUp by adding two sons, modify according to you logic
  void pushUp(int v, int tl, int tr) {
    assert(tl != tr);
    t[v] = std::max(t[v * 2], t[v * 2 + 1]);
  }

  void pushDown(int v, int tl, int tr) {
    assert(tl != tr);
    if (lazy[v] == 0) return;
    int tm = (tl + tr) / 2;
    t[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
  }

  // a[] && v are both 1-index
  void build(T a[], int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    pushUp(v, tl, tr);
  }

  // Single point update
  void update(int v, int tl, int tr, int pos, T val) {
    if (tl == tr) {
      t[v] += val;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(v * 2, tl, tm, pos, val);
    } else {
      update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    pushUp(v, tl, tr);
  }

  // Segment update with lazy operation
  void update(int v, int tl, int tr, int l, int r, T val) {
    if (l > r) return;
    if (l == tl && r == tr) {
      t[v] += val;
      lazy[v] += val;
    } else {
      pushDown(v, tl, tr);
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, std::min(r, tm), val);
      update(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val);
      pushUp(v, tl, tr);
    }
  }

  T query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && tr == r) {
      return t[v];
    }
    pushDown(v, tl, tr);
    int tm = (tl + tr) / 2;
    return std::max(query(v * 2, tl, tm, l, std::min(r, tm)), 
      query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n = 5;
  long long a[n + 1];  // a should be 1-index
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }

  SegTree<long long> s = SegTree<long long>(n);
  s.build(a, 1, 1, n); // start from 1st node in seg tree, also 1-index

  s.update(1, 1, n, 1, 2, 10);
  std::cout << s.query(1, 1, 5, 1, 5) << "\n";

  return 0;
}
