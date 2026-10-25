class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> store;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<n; i++){
            if(grid[i][0] == 0){
                store.push({i, 0});
                grid[i][0] = 1;
            }
            if(grid[i][m-1] == 0){
                store.push({i, m-1});
                grid[i][m-1] = 1;
            }
        }

        for(int i=0; i<m; i++){
            if(grid[0][i] == 0){
                store.push({0, i});
                grid[0][i] = 1;
            }
            if(grid[n-1][i] == 0){
                store.push({n-1, i});
                grid[n-1][i] = 1;
            }
        }

        while(!store.empty()){
            auto[r, c] = store.front();
            store.pop();

            for(int a=0; a<4; a++){
                int nr = r + dx[a];
                int nc = c + dy[a];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    store.push({nr, nc});
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    ans++;
                    grid[i][j] = 1;
                    store.push({i, j});

                    while(!store.empty()){
                        auto[r, c] = store.front();
                        store.pop();

                        for(int a=0; a<4; a++){
                            int nr = r + dx[a];
                            int nc = c + dy[a];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0){
                                grid[nr][nc] = 1;
                                store.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};