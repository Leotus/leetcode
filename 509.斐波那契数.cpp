#include <iostream>
#include <vector>
using namespace std;

/*
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
*/

/* 自顶向下，无优化 */
class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        else if (N == 1) {
            return 1;
        }
        else {
            return fib(N - 1) + fib(N - 2);
        }
    }
};

/* 自顶向下，备忘录优化 */
class Solution {
public:
    int helper(int N, vector<int>& mano) {
        if (N == 0) {
            return 0;
        }
        else if (N == 1) {
            return 1;
        }
        else {
            if (mano.at(N) != 0) {
                return mano.at(N);
            }
            else {
                mano[N] = helper(N - 1, mano) + helper(N - 2, mano);
                return mano[N];
            }
        }
    }
    int fib(int N) {
        vector<int>mano(N + 1, 0);
        return helper(N, mano);
    }
};

/* dp自底向上，备忘录 */
class Solution {
public:
    int fib(int N) {
        if (N == 0) { return 0; }
        else if (N == 1) { return 1; }
        else {
            vector<int>mano(N + 1, 0);
            mano[0] = 0;
            mano[1] = 1;
            for (int i = 2; i <= N; i++) {
                mano[i] = mano[i - 1] + mano[i - 2];
            }
            return mano[N];
        }
    }
};

/* dp自底向上，状态压缩，不再存储 */
class Solution {
public:
    int fib(int N) {
        if (N == 0) { return 0; }
        else if (N == 1) { return 1; }
        else {
            int prev = 0;
            int curr = 1;
            int sum = 0;
            for (int i = 2; i <= N; i++) {
                sum = prev + curr;
                prev = curr;
                curr = sum;
            }
            return sum;
        }
    }
};

