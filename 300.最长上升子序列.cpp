#include <iostream>
#include <vector>
using namespace std;
#define max(a,b) a>b?a:b
/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int* dp = new int[nums.size()]();// dp[i]表示nums[i]的最长递增子序列的长度
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int>a({ -2,-1 });
    int num = s->lengthOfLIS(a);
    cout << num;
    return 0;
}
