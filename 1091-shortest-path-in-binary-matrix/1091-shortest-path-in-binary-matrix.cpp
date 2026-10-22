class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> store;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));

        dis[0][0] = 1; 
        store.push({1, 0, 0});

        int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        while (!store.empty()) {
            auto [d, r, c] = store.top();
            store.pop();

            if (r == n - 1 && c == n - 1) return d;
            if (d > dis[r][c]) continue;

            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    if (dis[nr][nc] > d + 1) {
                        dis[nr][nc] = d + 1;
                        store.push({d + 1, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};