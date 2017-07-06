//
//  main.cpp
//  537. Complex Number Multiplication
//
//  Created by Ruiwen Feng on 2017/7/6.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 Given two strings representing two complex numbers.
 
 You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
 
 Example 1:
 Input: "1+1i", "1+1i"
 Output: "0+2i"
 Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
 Example 2:
 Input: "1+-1i", "1+-1i"
 Output: "0+-2i"
 Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 Note:
 
 The input strings will not have extra blank.
 The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
 
 思路：分割字符串取得实部和虚部，然后按照法则一步一步来。
 主要难度在分割字符串。
 
 
 
 Runtime: 0 ms
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    void Tokenize(const string& str, vector<string>& tokens, const string& delimiters)
    {
        /*
         find() 可以在指定字符串中查找完全匹配子串的位置
         find_first_of() 在指定字符串中查找第一个任意匹配子串中字符的位置
         find_first_not_of() 在指定字符串中查找第一个不任意匹配子串中字符的位置
         */
        string::size_type lastPos = str.find_first_not_of(delimiters, 0);
        string::size_type pos     = str.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos)
        {
            tokens.push_back(str.substr(lastPos, pos - lastPos));
            lastPos = str.find_first_not_of(delimiters, pos);
            pos = str.find_first_of(delimiters, lastPos);
        }
    }
    string complexNumberMultiply(string a, string b) {
        vector<string> atokens;
        Tokenize(a, atokens, "+i");
        vector<string> btokens;
        Tokenize(b, btokens, "+i");
        int a_shi =atoi(atokens[0].c_str());
        int a_xu =atoi(atokens[1].c_str());
        int b_shi =atoi(btokens[0].c_str());
        int b_xu =atoi(btokens[1].c_str());

        int result_shi = a_shi * b_shi - a_xu * b_xu;
        int result_xu = a_shi * b_xu + a_xu * b_shi;
        char result[10];
        sprintf(result, "%d+%di",result_shi,result_xu);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    string result = solution.complexNumberMultiply("1+1i", "1+1i");
    std::cout << result <<endl;
    return 0;
}
