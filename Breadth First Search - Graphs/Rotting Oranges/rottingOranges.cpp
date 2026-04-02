#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int time = 0;
        int fresh = 0;
        queue<pair<int,int>> queue;

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 1)
                    fresh++;
                if(grid[r][c] == 2)
                    queue.push(make_pair(r, c));
            }
        }

        while(queue.size() > 0 && fresh > 0) {
            int len = queue.size();
            for(int i = 0; i < len; i++) {
                auto [r, c] = queue.front();
                queue.pop();

                vector<pair<int,int>> directions = {
                    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
                };

                for(auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if(isValid(grid, nr, nc, ROWS, COLS)) {
                        grid[nr][nc] = 2;
                        queue.push(make_pair(nr, nc));
                        fresh--;
                    }
                }
            }
            time++;
        }

        if(fresh == 0)
            return time;
        return -1;
    }

    bool isValid(vector<vector<int>>& grid, int r, int c, int ROWS, int COLS) {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0 || grid[r][c] == 2)
            return false;
        return true;
    }
};
