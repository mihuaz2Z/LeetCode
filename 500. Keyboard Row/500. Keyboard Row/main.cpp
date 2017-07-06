//
//  main.cpp
//  500. Keyboard Row
//
//  Created by Ruiwen Feng on 2017/7/6.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
American keyboard
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
 
 思路：
 把每一位的字母转化为int类型来比较。
 <利用map生成一张hash表。其中三行字母分别对应1，2，3>
 然后来一个单词，就把第一个字母进hash表拿到基准。
 然后hash，其他字母是否和这个基准相等，不相等就剔除。
 /嘿嘿，还可以/
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    
    map<char,int> createHash(void) {
        map<char,int> hash_map = {pair<char,int>('q',1),pair<char,int>('w',1),pair<char,int>('e',1),pair<char,int>('r',1),pair<char,int>('t',1),pair<char,int>('y',1),pair<char,int>('u',1),pair<char,int>('i',1),pair<char,int>('o',1),pair<char,int>('p',1),pair<char,int>('Q',1),pair<char,int>('W',1),pair<char,int>('E',1),pair<char,int>('R',1),pair<char,int>('T',1),pair<char,int>('Y',1),pair<char,int>('U',1),pair<char,int>('I',1),pair<char,int>('O',1),pair<char,int>('P',1),pair<char,int>('a',2),pair<char,int>('s',2),pair<char,int>('d',2),pair<char,int>('f',2),pair<char,int>('g',2),pair<char,int>('h',2),pair<char,int>('j',2),pair<char,int>('k',2),pair<char,int>('l',2),pair<char,int>('A',2),pair<char,int>('S',2),pair<char,int>('D',2),pair<char,int>('F',2),pair<char,int>('G',2),pair<char,int>('H',2),pair<char,int>('J',2),pair<char,int>('K',2),pair<char,int>('L',2),pair<char,int>('z',3),pair<char,int>('x',3),pair<char,int>('c',3),pair<char,int>('v',3),pair<char,int>('b',3),pair<char,int>('n',3),pair<char,int>('m',3),pair<char,int>('Z',3),pair<char,int>('X',3),pair<char,int>('C',3),pair<char,int>('V',3),pair<char,int>('B',3),pair<char,int>('N',3),pair<char,int>('M',3)};
        return hash_map;
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        map<char,int> hashMap = createHash();
        for (int i = 0; i < words.size(); i ++) {
            int key = hashMap[words[i][0]];
            int j;
            for (j = 1; j < words[i].size(); j ++) {
                if (key != hashMap[words[i][j]]) {
                    break;
                }
            }
            if (j == words[i].size()) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    vector<string> input = {"Hello", "Alaska", "Dad", "Peace"};
    Solution solution;
    vector<string> result = solution.findWords(input);
    cout << "result:";
    for (int i = 0; i < result.size(); i ++) {
        cout <<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
