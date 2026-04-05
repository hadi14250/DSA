#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> visited(ROWS, vector<int>(COLS, 0));

        if(grid[0][0] == 1 || grid[ROWS - 1][COLS - 1] == 1)
            return -1;

        return bfs(grid, visited, ROWS, COLS);
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int ROWS, int COLS) {
        queue<pair<int,int>> queue;

        queue.push({0, 0});
        visited[0][0] = 1;

        int shortest_length = 1;

        while(queue.size() > 0) {
            int len = queue.size();
            for(int i = 0; i < len; i++) {
                auto [r, c] = queue.front();
                queue.pop();

                if(r == ROWS - 1 && c == COLS - 1)
                    return shortest_length;

                vector<pair<int,int>> directions = {
                    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
                };

                for(auto [dr, dc] : directions) {
                    int nr = dr + r;
                    int nc = dc + c;
                    if(isValid(grid, visited, nr, nc, ROWS, COLS)) {
                        queue.push(make_pair(nr, nc));
                        visited[nr][nc] = 1;
                    }
                }
            }
            shortest_length++;
        }
        return -1;
    }

    bool isValid(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c, int ROWS, int COLS) {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 1 || visited[r][c] == 1)
            return false;
        return true;
    }
};
