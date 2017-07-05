//
//  main.cpp
//  535. Encode and Decode TinyURL
//
//  Created by Ruiwen Feng on 2017/7/5.
//  Copyright © 2017年 Ruiwen Feng. All rights reserved.
//

/*
 
 TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
 
 Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
 
 没什么好说的。
 
 */

#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;


class Solution {
    
    map<string,string> saveMap;
    map<string,int> saveNamedMap;

public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (saveNamedMap[longUrl]) {
            stringstream ss;
            string s;
            ss << saveNamedMap[longUrl];
            ss >> s;
            return s;
        }
        saveNamedMap.insert(map<string,int>::value_type(longUrl,saveMap.size()));
        stringstream ss;
        string s;
        ss << saveNamedMap[longUrl];
        ss >> s;
        saveMap.insert(map<string,string>::value_type(s,longUrl));
        return s;
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return saveMap[shortUrl];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout<<solution.decode(solution.encode("wocao."))<<endl;
    
    return 0;
}
