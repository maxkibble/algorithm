#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a[1000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  printf("%d\n", a[1]);
  return 0;
}
