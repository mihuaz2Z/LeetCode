//
//  main.cpp
//  617. Merge Two Binary Trees
//
//  Created by Ruiwen Feng on 2017/7/5.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

#include <iostream>
#include <vector>

/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input:
Tree 1                     Tree 2
1                         2
/ \                       / \
3   2                     1   3
/                           \   \
5                             4   7
Output:
Merged tree:
3
/ \
4   5
/ \   \
5   4   7
Note: The merging process must start from the root nodes of both trees.*/

/*
 
 这题木有头绪。想来还是树忘记的差不多。
 补一下树的遍历什么的，回忆下树怎么操作应该可以。
 
 利用递归。没啥好说的。
 
 */




using namespace std;

 struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
 
        TreeNode* node = new TreeNode(t1->val + t2->val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
        return node;
    }
};


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
