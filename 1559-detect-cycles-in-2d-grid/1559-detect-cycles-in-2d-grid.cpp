class Solution {
public:
    bool dfs(int row, int col, int pRow, int pCol, vector<vector<char>>& grid, vector<vector<int>>& vis, char val){
        int i = grid.size();
        int j = grid[0].size();

        if(row<0 || row>=i || col<0 || col>=j || grid[row][col]!=val) return false;


        if(vis[row][col]==1) return true;

        vis[row][col]=1;

        if(!(row-1==pRow && col==pCol)){
            if(dfs(row-1, col, row, col, grid, vis, val)) return true;
        }
        if(!(row+1==pRow && col==pCol)){
            if(dfs(row+1, col, row, col, grid, vis, val)) return true;
        }
        if(!(row==pRow && col-1==pCol)){
            if(dfs(row, col-1, row, col, grid, vis, val)) return true;
        }
        if(!(row==pRow && col+1==pCol)){
            if(dfs(row, col+1, row, col, grid, vis, val)) return true;
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0){
                    if(dfs(i, j, -1, -1, grid, vis, grid[i][j])) return true;
                }
            }
        }
        return false;
    }
};