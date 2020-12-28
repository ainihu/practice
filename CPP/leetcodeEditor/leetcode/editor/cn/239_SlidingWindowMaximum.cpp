//给你一个zheng's数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向
//右移动一位。 
//
// 返回滑动窗口中的最大值。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,-1], k = 1
//输出：[1,-1]
// 
//
// 示例 4： 
//
// 
//输入：nums = [9,11], k = 2
//输出：[11]
// 
//
// 示例 5： 
//
// 
//输入：nums = [4,-2], k = 2
//输出：[4] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// -104 <= nums[i] <= 104 
// 1 <= k <= nums.length 
// 
// Related Topics 堆 Sliding Window 
// 👍 678 👎 0


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

namespace SlidingWindowMaximum {
    using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k) {
            if (nums.size() < 2) {
                return nums;
            }

            deque<int> index;
            vector<int> result;

            for (int i = 0; i < nums.size(); ++i) {
                while (!index.empty() && index.back() <= nums[i]) {
                    index.pop_back();
                }
                index.push_back(i);
                if (index.front() <= i - k) {
                    index.pop_front();
                }
                if (i + 1 >= k) {
                    result.push_back(nums[index.front()]);
                }
            }

            return result;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)


    TEST(SlidingWindowMaximum, test01) {
        Solution s;

        vector<int> result{1, 3, -1, -3, 5, 3, 6, 7};
        for (int i : s.maxSlidingWindow(result, 3)) {
            cout << i << " ";
        }
        cout << endl;
    }

    TEST(SlidingWindowMaximum, test02) {
        Solution s;

        vector<int> result{1};
        for (int i : s.maxSlidingWindow(result, 3)) {
            cout << i << " ";
        }
        cout << endl;
    }

    TEST(SlidingWindowMaximum, test03) {
        Solution s;

        vector<int> result{1, 2};
        for (int i : s.maxSlidingWindow(result, 3)) {
            cout << i << " ";
        }
        cout << endl;
    }
}