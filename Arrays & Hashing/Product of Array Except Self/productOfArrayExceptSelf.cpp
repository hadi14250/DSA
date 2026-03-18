#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> sufix(nums.size());

        prefix[0] = 1;
        for(size_t i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        
        sufix[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            sufix[i] = sufix[i + 1] * nums[i + 1];
        }
        for(size_t i = 0; i < nums.size(); i++) {
            nums[i] = prefix[i] * sufix[i];
        }
        return nums;
    }
};
