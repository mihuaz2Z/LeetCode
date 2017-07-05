//
//  main.cpp
//  476. Number Complement
//
//  Created by Ruiwen Feng on 2017/7/5.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 
 Note:
 The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 You could assume no leading zero bit in the integer’s binary representation.
 Example 1:
 Input: 5
 Output: 2
 Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 Example 2:
 Input: 1
 Output: 0
 Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 
 
 做完看答案简直无语。。 0ms.....
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while(mask&num)
            mask<<=1;
        return ~mask^num;
    }
};
 
 
 我自己的思路简直。。
 
 最优解的思路是：
 把0按位取反。得到全是1的mask。
 用一个循环得到num的1的最高位之下全为0的mask。
 对mask取反得到和num同最高位的mask
 然后和num异或，把num全部取反。
 
 总结：位操作的高效体现的淋漓尽致。
 
 */



#include <iostream>

using namespace std;


class Solution {
public:
    int findComplement(int num) {
        int eor = num;
        int wei = 0;
        
        while (eor) {
            wei ++;
            eor = eor/2;
        }
        eor = 0;
        
        for (int i =0; i < wei; i ++) {
            eor = eor<<1;
            int g = num&0x1;
            if (g != 1) {
                eor += 1;
            }
            num = num>>1;
        }
        
        int result = 0;
        for (int i =0; i < wei; i ++) {
            result = result<<1;
            result += eor&0x1;
            eor = eor>>1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    int result = solution.findComplement(1999);
    std::cout << result <<endl;
    return 0;
}
