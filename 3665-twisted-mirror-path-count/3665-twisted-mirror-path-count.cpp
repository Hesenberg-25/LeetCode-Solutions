class Solution {
    const int MOD = 1e9 + 7;

    pair<int, int> simulate(int r, int c, int dir, const vector<vector<int>>& grid, int m, int n) {
        int curr_r = r;
        int curr_c = c;
        int curr_dir = dir;

        while (true) {
            int nr = curr_r + (curr_dir == 1 ? 1 : 0);
            int nc = curr_c + (curr_dir == 0 ? 1 : 0);
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                return {-1, -1};
            }

            if (nr == m - 1 && nc == n - 1) {
                return {nr, nc};
            }

            if (grid[nr][nc] == 0) {
                return {nr, nc};
            }

            if (curr_dir == 0) { 
                curr_r = nr;
                curr_c = nc;
                curr_dir = 1;
            } else {            
                curr_r = nr;
                curr_c = nc;
                curr_dir = 0;
            }
        }
    }

    int dfs(int r, int c, const vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n) {
        if (r == m - 1 && c == n - 1) {
            return 1;
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        long long ways = 0;

        auto [r_right, c_right] = simulate(r, c, 0, grid, m, n);
        if (r_right != -1) {
            ways = (ways + dfs(r_right, c_right, grid, dp, m, n)) % MOD;
        }

        auto [r_down, c_down] = simulate(r, c, 1, grid, m, n);
        if (r_down != -1) {
            ways = (ways + dfs(r_down, c_down, grid, dp, m, n)) % MOD;
        }

        return dp[r][c] = ways;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1) return 1;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(0, 0, grid, dp, m, n);
    }
};