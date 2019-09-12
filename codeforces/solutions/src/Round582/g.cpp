#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

struct Edge {
  int fr, to, w;
  Edge(int a, int b, int c): fr(a), to(b), w(c) {}
  bool operator < (const Edge &obj) const {
    return w < obj.w;
  }
};

struct Query {
  int q, i;
  long long val;
  Query(int a, int b): q(a), i(b), val(0) {}
};

int n, m;
vector<Edge> E;
vector<Query> Q;

// dsu
int ei;
long long ans;
vector<int> F, S;
int f(int x) {
  if (F[x] == x) return x;
  return F[x] = f(F[x]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    E.emplace_back(Edge(u, v, x));
  }
  sort(E.begin(), E.end());

  for (int i = 0; i < m; i++) {
    int qi;
    cin >> qi;
    Q.push_back(Query(qi, i));
  }
  auto cmp_q1 = [](const Query &q1, const Query &q2) {
    return q1.q < q2.q;
  };
  sort(Q.begin(), Q.end(), cmp_q1);

  F.resize(n + 1), S.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    F[i] = i;
    S[i] = 1;
  }
  
  auto g = [](int x) {
    return x * 1ll * (x - 1) / 2;
  };

  for (int i = 0; i < m; i++) {
    while (ei < n - 1 && E[ei].w <= Q[i].q) {
      int x = E[ei].fr, y = E[ei].to;
      int fx = f(x), fy = f(y);
      if (fx != fy) {
        ans -= g(S[fx]);
        ans -= g(S[fy]);
        ans += g(S[fx] + S[fy]);
        S[fx] += S[fy];
        S[fy] = 0;
        F[fy] = fx;
      }
      ei++;
    }
    Q[i].val = ans;
  }
  
  auto cmp_q2 = [](const Query &q1, const Query &q2) {
    return q1.i < q2.i;
  };
  sort(Q.begin(), Q.end(), cmp_q2);
  for (auto item: Q) cout << item.val << " ";

  return 0;
}
