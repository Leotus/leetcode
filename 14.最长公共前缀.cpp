/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.25%)
 * Total Accepted:    59.2K
 * Total Submissions: 183.1K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        for(int i = 0;;i++){//i为在字符串中遍历的长度
            for(vector<string>::iterator it = strs.begin();it!=strs.end();++it){
                if(((*it)[i]) && ((*it)[i] == (*strs.begin())[i])){
                    continue;
                }else{
                    return (*strs.begin()).substr(0,i);
                }
            }
        }
    }
};

int main(){
    Solution solution;
    string str[] = {"flower","flow","flight"};
    vector<string> *vec = new vector<string>(str,str+sizeof(str)/sizeof(string));
    cout << solution.longestCommonPrefix(*vec);
    return 0;
}
