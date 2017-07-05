//
//  main.cpp
//  561. Array Partition I
//
//  Created by Ruiwen Feng on 2017/7/5.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//


/*
 
 //居然看不懂答案。。我也是醉了。
 答案O(n)的时间复杂度简直碉堡了。。
 
 我这个手写了了一个快速排序，然后取偶数位的数相加。。相形见绌。。
 
 
 */


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    
    int partition(vector<int> *nums,int low,int high) {
        int privotKey = (*nums)[low];
        while(low < high){
            while(low < high  && (*nums)[high] >= privotKey ) --high;
            swap((*nums)[low], (*nums)[high]);
            
            while(low < high  && (*nums)[low] <= privotKey ) ++low;
            swap((*nums)[low], (*nums)[high]);
        }
        return low;
    }
    
    void quickSort(vector<int> *nums,int low,int high) {
        if (low < high) {
            int pivotlocation = partition(nums, low, high); //将表一分为二
            quickSort(nums, low, pivotlocation-1); //递归对低子表递归排序
            quickSort(nums, pivotlocation+1,high); //递归对高子表递归排序
        }
    }
    
    int arrayPairSum(vector<int>& nums) {
        
        quickSort(&nums, 0, int(nums.size()-1));

        int result = 0;
        for (int i =0; i < nums.size() ; i +=2) {
            result += nums[i];
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {

    Solution * solution = new Solution();
    vector<int> gaga = {9,1};
    
    int resukt = solution->arrayPairSum(gaga);
    
    std::cout << "resukt:" <<resukt <<endl;
    return 0;
}
