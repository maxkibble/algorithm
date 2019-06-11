    
/*=====================================
*   
*   AUTHOR : kvirus
*   
*   PROBLEM: leetcode 316, 1081
*
=====================================*/

\\ 题意：给定一个字符串，删除其中的重复的字符串，即每一个字符只能出现一次，
\\ 并保证最后的结果是字典序最小的子串。


\\ 解题思路是：
\\ 	依次遍历每个字符，比较当前字符和之前已记录的字符的大小关系，
\\  如果当前字符比之前最后一个字符小，并且之后该字符依旧存在，那么就把之前的字符给删掉。
class Solution {
public:
    string smallestSubsequence(string text) {
        int occ[26] = {0}, left[26] = {0};
        for (auto c: text) left[c - 'a'] ++;
        string ans = "";
        for (auto c: text) {
            left[c - 'a'] --;
            if (occ[c - 'a'] == 0) {
                int j = ans.length();
                while (--j > -1) {
                    if (left[ans[j] - 'a'] == 0 || ans[j] < c) break;
                    else occ[ans[j] - 'a'] = 0;
                }
                if (j != ans.length() - 1) ans = ans.substr(0, j + 1);
                ans.append(1, c);
                occ[c - 'a'] = 1;
            }
        }
        return ans;
    }
};