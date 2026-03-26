#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total_sum = 0;
        int min_len = nums.size() + 1;
        int l = 0;

        for(int r = 0; r < (int)nums.size(); r++) {
            total_sum += nums[r];
            while(total_sum >= target) {
                min_len = min(min_len, r - l + 1);
                total_sum -= nums[l];
                l++;
            }
        }
        return min_len == (int)nums.size() + 1 ? 0 : min_len;
    }
};
