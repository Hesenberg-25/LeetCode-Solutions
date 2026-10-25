class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& block : flights) {
            adj[block[0]].push_back({block[1], block[2]});
        }

        vector<int> dis(n, 1e9);
        dis[src] = 0;

        queue<tuple<int, int, int>> store;
        store.push({0, src, 0});
        
        while (!store.empty()) {
            auto [stops, node, dist] = store.front();
            store.pop();

            if (stops > k) continue;

            for (const auto& [next, cost] : adj[node]) {
                if (dist + cost < dis[next]) {
                    dis[next] = dist + cost;
                    store.push({stops + 1, next, dist + cost});
                }
            }
        }

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};