class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& adj, vector<int>& vis){
        vis[i]=1;
        for(int  adjs : adj[i]){
            if(vis[adjs]==0){
                if(dfs(adjs, i, adj, vis)) return true;
            }
            else if(vis[adjs]==1) return true;
        }
        vis[i]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto& pre : prerequisites){
            int course = pre[0];
            int preC = pre[1];

            adj[preC].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        for(int a=0; a<numCourses; a++){
            if(dfs(a, -1, adj, vis)) return false;
        }
        return true;
    }
};