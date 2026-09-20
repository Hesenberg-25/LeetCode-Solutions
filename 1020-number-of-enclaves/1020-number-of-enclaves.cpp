class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

     
        if (r<0 || r>=n || c<0 || c>=m || grid[r][c]!=1) {
            return;
        }
        grid[r][c]=0;

        dfs(r - 1, c, grid);
        dfs(r + 1, c, grid); 
        dfs(r, c - 1, grid); 
        dfs(r, c + 1, grid);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        for (int i=0; i<n; i++) {
            if (grid[i][0]==1) dfs(i, 0, grid);
            if (grid[i][m - 1]==1) dfs(i, m - 1, grid);
        }

        for (int j=0; j<m; j++) {
            if (grid[0][j]==1) dfs(0, j, grid);
            if (grid[n - 1][j]==1) dfs(n - 1, j, grid);
        }
        int enclaves=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};