#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        if(!ROWS || !COLS)
            return -1;

        int islands = 0;

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == '1') {
                    bfs(r, c, ROWS, COLS, grid);
                    islands++;
                }
            }
        }
        return islands;
    }

    void bfs(int r, int c, int ROWS, int COLS, vector<vector<char>>& grid) {
        if (!isValid(r, c, ROWS, COLS, grid))
            return;

        queue<pair<int,int>> queue;

        queue.push(make_pair(r, c));
        grid[r][c] = '0';

        while(queue.size() > 0) {
            int len = queue.size();
            for(int i = 0; i < len; i++) {
                pair<int,int> coordinate = queue.front();
                queue.pop();
                int r = coordinate.first;
                int c = coordinate.second;

                if(isValid(r + 1, c, ROWS, COLS, grid)) {
                    queue.push(make_pair(r + 1, c));
                    grid[r + 1][c] = '0';
                }
                if(isValid(r - 1, c, ROWS, COLS, grid)) {
                    queue.push(make_pair(r - 1, c));
                    grid[r - 1][c] = '0';
                }
                if(isValid(r, c + 1, ROWS, COLS, grid)) {
                    queue.push(make_pair(r, c + 1));
                    grid[r][c + 1] = '0';
                }
                if(isValid(r, c - 1, ROWS, COLS, grid)) {
                    queue.push(make_pair(r, c - 1));
                    grid[r][c - 1] = '0';
                }
            }
        }
    }

    bool isValid(int r, int c, int ROWS, int COLS, vector<vector<char>>& grid) {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == '0')
            return false;
        return true;
    }
};
