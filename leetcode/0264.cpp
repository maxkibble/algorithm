/*=====================================
*   
*   AUTHOR : maxkibble
*   CREATED: 2019.06.01 10:38:43
*   PROBLEM: leetcode 264, Ugly Number II
*
=====================================*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v{1};
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 0; i < n - 1; i++) {
            int v2 = v[i2] * 2;
            int v3 = v[i3] * 3;
            int v5 = v[i5] * 5;
            int nxt = min(v2, min(v3, v5));
            if (nxt == v2) i2++;
            if (nxt == v3) i3++;
            if (nxt == v5) i5++;
            v.push_back(nxt);
        }
        return v[n - 1];
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.nthUglyNumber(1500);  // should be 859963392 
    return 0;
}
