#include <iostream>
#include <vector>
using namespace std;

#define min(A,B) (A<B?A:B)

//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
//如果没有任何一种硬币组合能组成总金额，返回 - 1。
//示例 1:
//
//输入: coins = [1, 2, 5], amount = 11
//输出 : 3
//解释 : 11 = 5 + 5 + 1

//示例 2 :
//
//输入 : coins = [2], amount = 3
//输出 : -1

/* 自顶向下，无优化 -> 在leetcode上超出时间限制 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        else if (amount < 0) {
            return -1;
        }
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int sub = coinChange(coins, amount - coins[i]);
            if (sub == -1)continue;
            else {
                res = (res < 1 + sub ? res : 1 + sub);
            }
        }
        if (res == INT_MAX) {
            return -1;
        }
        else {
            return res;
        }
    }
};


/* 自顶向下，备忘录优化 -> 在leetcode上超出时间限制 */
class Solution {
public:
    int dp(vector<int>& coins, int amount, vector<int>& mano) {
        if (amount == 0) {
            return 0;
        }
        else if (amount < 0) {
            return -1;
        }
        if (mano[amount] != 0) {
            return mano[amount];
        }
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int sub = dp(coins, amount - coins[i], mano);
            if (sub == -1)continue;
            else {
                res = (res < 1 + sub ? res : 1 + sub);
                mano[amount] = res;
            }
        }
        if (res == INT_MAX) {
            return -1;
        }
        else {
            return res;
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mano(amount + 1, 0);
        return dp(coins, amount, mano);
    }
};

/* 自底向上，备忘录 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mano(amount + 1, amount + 1);
        mano[0] = 0;
        for (int i = 0; i < mano.size(); i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] < 0)continue;
                mano[i] = min(mano[i], 1 + mano[i - coins[j]]);
            }
        }
        return (mano[amount] == amount + 1) ? -1 : mano[amount];
    }
};
