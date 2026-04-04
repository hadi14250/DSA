#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visited;

        for(int i = 0; i < numCourses; i++) {
            adjList[i] = {};
        }
        for(auto& pre : prerequisites) {
            int src = pre[0];
            int dst = pre[1];
            adjList[src].push_back(dst);
        }
        for(int c = 0; c < numCourses; c++) {
            if(!dfs(c, adjList, visited)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int course, unordered_map<int,vector<int>> adjList, unordered_set<int> visited) {
        if(visited.count(course))
            return false;
        if(adjList[course].empty())
            return true;

        visited.insert(course);
        for(int pre : adjList[course]) {
            if(!dfs(pre, adjList, visited))
                return false;
        }
        visited.erase(course);
        adjList[course].clear();
        return true;
    }
};
