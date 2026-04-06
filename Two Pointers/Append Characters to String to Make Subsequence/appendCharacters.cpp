#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        size_t i = 0;
        size_t j = 0;

        while (i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        return t.size() - j;
    }
};
