//
//  main.cpp
//  561. Array Partition I
//
//  Created by Ruiwen Feng on 2017/7/5.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    
    int partition(vector<int> *nums,int low,int high) {
        int privotKey = (*nums)[low];                                 //基准元素
        while(low < high){                                            //从表的两端交替地向中间扫描
            while(low < high  && (*nums)[high] >= privotKey ) --high;  //将比基准元素小的交换到低端
            swap((*nums)[low], (*nums)[high]);
            
            while(low < high  && (*nums)[low] <= privotKey ) ++low; //将比基准元素大的交换到高处
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
