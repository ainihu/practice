/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_62.hpp
 * 时间: 9/1/2019-6:11 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/unique-paths/
 * 解题思路：
 */

class Solution {
public:
    map<pair<int, int>, int> mem;
    int dp(int x, int y) {
        if (x <= 0 || y <= 0) {
            return 0;
        } else if(x == 1 || y == 1) {
            return 1;
        }
        auto key = make_pair(x, y);
        if (!mem[key]) {
            mem[key] = dp(x - 1, y) + dp(x, y - 1);
        }

        return mem[key];
    }
    int uniquePaths(int m, int n) {
        return dp(m, n);
    }
};

void test() {
    Solution s;
    cout << s.uniquePaths(7, 3) << endl;
}