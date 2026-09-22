class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> store;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    store.push({i,j});
                    vis[i][j]=true;
                }
            }
        }

        int rowD[]={-1, 1, 0, 0};
        int colD[]={0, 0, -1, 1};

        while(!store.empty()){
            auto [r,c] = store.front();
            store.pop();

            for(int k=0; k<4; k++){
                int gr = r + rowD[k];
                int gc = c + colD[k];

                if(gr>=0 && gr<n && gc>=0 && gc<m && !vis[gr][gc]){
                    vis[gr][gc]=true;
                    ans[gr][gc] = ans[r][c]+1;
                    store.push({gr,gc});
                }
            }
        }
        return ans;
    }
};