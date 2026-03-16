#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams;
        vector<string> copied;
        vector<vector<string>> finalVector;
        copied = strs;
        for (size_t i = 0; i < strs.size(); i++) {
            sort(copied[i].begin(), copied[i].end());
            (anagrams[copied[i]]).push_back(strs[i]);
        }

        for(auto& [key, vec] : anagrams) {
            finalVector.push_back(vec);
        }
        return finalVector;
    }
};
