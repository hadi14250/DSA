#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> numMap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto& num : nums) {
            numMap[num]++;
        }

        for(auto& [num,freq] : numMap) {
            pq.push({freq,num});
            if((int)pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            auto [freq,num] = pq.top();
            res.push_back(num);
            pq.pop();
        }
        return res;
    }
};
