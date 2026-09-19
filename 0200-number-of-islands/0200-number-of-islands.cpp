#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void bfs(int i, int j, vector<vector<bool>>& vis, const vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> store;
        store.push({i, j});
        vis[i][j] = true;

        int rowD[] = {-1, 1, 0, 0};
        int colD[] = {0, 0, -1, 1};

        while (!store.empty()) {
            auto it = store.front();
            int row = it.first;
            int col = it.second;
            store.pop();

            for (int k = 0; k < 4; k++) {
                int rolC = row + rowD[k];
                int colC = col + colD[k];

                if (rolC >= 0 && rolC < n && colC >= 0 && colC < m) {
                    if (grid[rolC][colC] == '1' && !vis[rolC][colC]) {
                        vis[rolC][colC] = true;
                        store.push({rolC, colC});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int island = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    island++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return island;
    }
};