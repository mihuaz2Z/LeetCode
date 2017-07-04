//
//  main.cpp
//  461. Hamming Distance
//
//  Created by Ruiwen Feng on 2017/7/4.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>

using namespace std;


/*
 
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 
 Given two integers x and y, calculate the Hamming distance.
 
 Note:
 0 ≤ x, y < 231.
 
 Example:
 
 Input: x = 1, y = 4
 
 Output: 2
 
 Explanation:
 1   (0 0 0 1)
 4   (0 1 0 0)
 ↑   ↑
 
 The above arrows point to positions where the corresponding bits are different.
 
 
 自己写的太挫了。
 
 答案思路：
 先把两个数异或，再求结果1的位数。
 
 而求某一个数的二进制表示中1的个数
 while (n >0 ) {
    count ++;
    n &= (n-1); //与比自己小1的数相与，最低位抹零。
 }

 所以答案为：
 

class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int eor_xy = x^y;
        
        int dif = 0;
        while (eor_xy) {
            dif ++;
            eor_xy = eor_xy & (eor_xy-1);
        }
        
        return dif;
    }
};
 */


class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int dif = 0;
        for (int i = 0; i < 32 ; i ++) {
            if (((x>>i)&0x1)^((y>>i)&0x1)) {
                dif ++;
            }
        }
        return dif;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution * solution = new Solution();
    
    int result = solution->hammingDistance(3, 1);
    
    
    std::cout << result <<endl;
    return 0;
}
