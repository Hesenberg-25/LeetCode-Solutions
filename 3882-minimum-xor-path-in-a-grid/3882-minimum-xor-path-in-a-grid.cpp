class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n == 1 && m == 1) {
            return grid[0][0];
        }

        int dx[] = {0, 1};
        int dy[] = {1, 0};   

        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(1024, false)));

        queue<tuple<int, int, int>> store;
        store.push({grid[0][0],0,0});
        vis[0][0][0] = true;

        while(!store.empty()){
            auto[x, r, c] = store.front();
            store.pop();
            
            for(int a=0; a<2; a++){
                int rc = r + dx[a];
                int cc = c + dy[a];

                if(rc<n && cc<m){
                    int cX = x^grid[rc][cc];

                    if(!vis[rc][cc][cX]){
                        vis[rc][cc][cX] = true;
                        store.push({cX, rc, cc});
                    } 
                }
            } 
        }
        for (int x = 0; x < 1024; x++) {
            if (vis[n - 1][m - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};