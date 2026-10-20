class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1 && !vis[i][j]) {
                    int r1=i, c1=j, r2=i, c2=j;

                    queue<pair<int,int>> store;
                    store.push({i,j});
                    vis[i][j]=true;

                    while(!store.empty()){
                        auto [r, c] = store.front();
                        store.pop();

                        r2 = max(r2, r);
                        c2 = max(c2, c);

                        for (int d = 0; d < 4; d++) {
                            int nr = r + dRow[d];
                            int nc = c + dCol[d];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                                if (land[nr][nc] == 1 && !vis[nr][nc]) {
                                    vis[nr][nc] = true;
                                    store.push({nr, nc});
                                }
                            }
                        }
                    }
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        return ans;
    }
};