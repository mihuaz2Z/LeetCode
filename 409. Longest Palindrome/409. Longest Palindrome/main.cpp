//
//  main.cpp
//  409. Longest Palindrome
//
//  Created by Ruiwen Feng on 2017/7/4.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 
 Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 
 This is case sensitive, for example "Aa" is not considered a palindrome here.
 
 Note:
 Assume the length of given string will not exceed 1,010.
 
 Example:
 
 Input:
 "abccccdd"
 
 Output:
 7
 
 Explanation:
 One longest palindrome that can be built is "dccaccd", whose length is 7.
 
 
 思路：
 题意：选取字符串中的字符组成回文字符串，求最大长度。
 一开始理解错误。认为只有一个奇数个字符的子串能用来组合。
 其实奇数个字符的子串去掉一个字符后也可以用来进行组合。
 
 于是变成求：
 字符串中，偶数个数的子串+奇数个数的子串，其中最大的奇数个数的子串+1的字符串长度。
 结题思路：
 遍历字符串，求出偶串长度直接相加。奇串长度-1相加。
 如果有奇串，或者单个字符，则结果加1.
 
 */


class Solution {
public:
    int longestPalindrome(string s) {
        
        int result = 0;
        int flag_single = 0;
        while (s.size() >= 1 ) {
            char temp = s[0];
            vector<int> deleteArray;
            deleteArray.push_back(0);
            for (int i = 1; i < s.size(); i++) {
                if (temp == s[i]) {
                    deleteArray.push_back(i);
                }
            }
            
            if (deleteArray.size()>1) {
                if (deleteArray.size()%2 == 0) {
                    result += deleteArray.size();
                }
                else {
                    flag_single = 1;
                    result += deleteArray.size()-1;
                }
            }
            else {
                flag_single = 1;
            }
            
            for (int i = (int)deleteArray.size()-1; i >= 0 ; i --) {
                s.erase(deleteArray[i],1);
            }
            
            deleteArray.clear();
        }
        
        result += flag_single;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution * solution = new Solution();
    string *ca = new string("abababab");
    int result = solution->longestPalindrome(*ca);
    cout << result <<endl;
    return 0;
}
