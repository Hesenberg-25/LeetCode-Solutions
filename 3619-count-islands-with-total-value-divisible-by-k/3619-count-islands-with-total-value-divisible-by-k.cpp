class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int r, int c, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0)
            return 0;

        long long sum = grid[r][c];
        grid[r][c] = 0;

        sum += dfs(grid, r, c - 1, n, m);
        sum += dfs(grid, r, c + 1, n, m);
        sum += dfs(grid, r - 1, c, n, m);
        sum += dfs(grid, r + 1, c, n, m);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        long long qualify = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long inter = dfs(grid, i, j, n, m);
                    if (inter % k == 0) qualify++;
                }
            }
        }
        return qualify;
    }
};   