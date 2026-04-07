#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;

        for(int& num : nums) {
            if (numSet.count(num))
                return true;
            else
                numSet.insert(num);
        }
        return false;
    }
};
