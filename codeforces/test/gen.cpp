/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.08.05 13:17:29
*
=====================================*/

#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
  return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  int n = rand(2, 10);
  printf("%d\n", n);
  set<int> used;
  for (int i = 0; i < n; i++) {
    int x;
    do {
      x = rand(1, 10);
    } while (used.count(x));
    printf("%d ", x);
    used.insert(x);
  }
  puts("");
  return 0;
}

