class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& store){
        if(i>=m || j>=n) return 0;

        if(i==m-1 && j==n-1) return 1;

        if(store[i][j] != -1) return store[i][j];

        int down = dfs(i+1, j, m, n, store);
        int right = dfs(i, j+1, m, n, store);

        return store[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> store(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, store);
    }
};