class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);

        for( auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }

        queue<int>q;
        q.push(k);
        visited[k]=true;
        //BFS
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }

        for(auto &e: invocations){
            if(!visited[e[0]] && visited[e[1]]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int>result;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};