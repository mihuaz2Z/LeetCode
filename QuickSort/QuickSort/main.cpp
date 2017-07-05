//
//  main.cpp
//  QuickSort
//
//  Created by Ruiwen Feng on 2017/7/5.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


/*
 这里是来自封睿文的快速排序。
 
 
 */


class Sort {
    
    
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
};



int main(int argc, const char * argv[]) {
    
    Sort sort = *new Sort();
    vector<int> gaga = {1,3,5,3,8,2,1,7,8,6,5};
    sort.quickSort(&gaga, 0, 10);
    for (int i = 0; i < gaga.size(); i ++) {
        cout <<gaga[i]<<" ";
    }
    
    cout << "\n";
    return 0;
}
