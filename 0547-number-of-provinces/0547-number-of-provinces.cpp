class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis){
        vis[node] = true;
        for(int next=0; next<isConnected.size(); next++){
            if(isConnected[node][next] && !vis[next]){
                dfs(next, isConnected, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int province = 0;
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                province++;
                dfs(i, isConnected, vis);
            }
        }
        return province;
    }
};