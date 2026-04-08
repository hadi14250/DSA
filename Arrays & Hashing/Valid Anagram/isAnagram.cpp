#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;

        for(int i = 0; i < (int)s.size(); i++) {
            sMap[s[i]]++;
        }
        for(int i = 0; i < (int)t.size(); i++) {
            tMap[t[i]]++;
        }

        if(sMap.size() != tMap.size())
            return false;

        for(auto& [key, value] : sMap) {
            if (tMap.count(key) && tMap[key] == sMap[key])
                continue;
            else
                return false;
        }

        return true;
    }
};
