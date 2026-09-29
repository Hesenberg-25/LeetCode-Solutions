class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
        vis[node]=1;
        for(int adjs : adj[node]){
            if(vis[adjs]==0){
                if(dfs(adjs, adj, vis, ans)) return true;
            }
            else if(vis[adjs]==1) return true;
        }
        ans.push_back(node);
        vis[node]=2;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);

        for(const auto& pres : prerequisites){
            int course = pres[0];
            int pCourse = pres[1];
            adj[course].push_back(pCourse);
        }

        vector<int> vis(V, 0);
        vector<int> ans;

        for(int a=0; a<V; a++){
            if(vis[a]==0){
                if(dfs(a, adj, vis, ans)) return {};
            }
        }
        return ans;
    }
};