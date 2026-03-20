#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0, r = 0;
        int maxLen = 0;

        while (r < (int)s.size()) {
            if (!charSet.count(s[r])) {
                charSet.insert(s[r]);
                r++;
                maxLen = max(maxLen, r - l);
            } else {
                charSet.erase(s[l]);
                l++;
            }
        }
        return maxLen;
    }
};
