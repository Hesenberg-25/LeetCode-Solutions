class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis){
        vis[node]=1;

        for(int adjs : graph[node]){
            if(vis[adjs]==0){
                if(dfs(adjs, graph, vis)) return true;
            }
            else if(vis[adjs]==1) return true;
        }
        vis[node]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> vis(V, 0);
        vector<int> ans;

        for(int i=0; i<V; i++){
            if(vis[i]==0){
                dfs(i, graph, vis);
            }
        }
        for (int i = 0; i < V; i++) {
            if (vis[i] == 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};