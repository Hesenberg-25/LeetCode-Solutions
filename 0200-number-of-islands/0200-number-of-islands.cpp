#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '0';
            
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        int island = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    dfs(i, j, grid);
                }
            }
        }
        return island;
    }
};