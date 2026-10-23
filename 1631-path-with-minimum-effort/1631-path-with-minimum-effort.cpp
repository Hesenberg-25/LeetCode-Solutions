class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> store;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        store.push({0, 0, 0});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!store.empty()) {
            auto [diff, r, c] = store.top();
            store.pop();

            if (r == n - 1 && c == m - 1) {
                return diff;
            }

            if (diff > dist[r][c]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newEffort = max(diff, abs(heights[nr][nc] - heights[r][c]));

                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        store.push({newEffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};