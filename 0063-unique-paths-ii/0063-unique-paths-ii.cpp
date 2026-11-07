class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& store, vector<vector<int>>& obstacleGrid) {
        if (i >= n || j >= m || obstacleGrid[i][j] == 1) return 0;

        if (i == n - 1 && j == m - 1) return 1;

        if (store[i][j] != -1) return store[i][j];

        int down = dfs(i + 1, j, n, m, store, obstacleGrid);
        int right = dfs(i, j + 1, n, m, store, obstacleGrid);

        return store[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) return 0;

        vector<vector<int>> store(n, vector<int>(m, -1));

        return dfs(0, 0, n, m, store, obstacleGrid);
    }
};