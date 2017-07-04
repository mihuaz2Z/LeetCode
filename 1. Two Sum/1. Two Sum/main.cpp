//
//  main.cpp
//  1. Two Sum
//
//  Created by Ruiwen Feng on 2017/7/4.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 
 思路。
 利用要寻找的target-当前值得到目标值。
 如果目标值不存在于map中，就把当前值放入map，找下一个数。
 直到找到一组值得和等于目标值，则这组值就是我们需要的。
 输出需要数组下标
 利用map记录map中已保存的数的下标，以及当前的数的下标就可以得到解决的答案。
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> outvector;
        map<int,int> map;
        for (int i = 0; i < nums.size(); i ++) {
            int nextFind = target - nums[i];
            if (map.find(nextFind) != map.end()) {
                outvector.push_back(map[nextFind]);
                outvector.push_back(i);
                return outvector;
            }
            else
            {
                map[target-nextFind] = i;
            }
        }
        return outvector;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution * solution = new Solution();
    
    vector<int> temp = {3,2,4};
    
    vector<int> outvector = solution->twoSum(temp, 6);
    
    cout << "7="<<outvector[0]<<"+"<<outvector[1]<<endl;
    
    return 0;
}
