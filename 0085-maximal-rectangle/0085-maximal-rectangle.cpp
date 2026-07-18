class Solution {
private:
    int largestArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        int areaMax = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                areaMax = max(areaMax, (arr[ele] * (nse - pse - 1)));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int ele = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            areaMax = max(areaMax, (arr[ele] * (nse - pse - 1)));
        }

        return areaMax;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        int maxxAre = 0;

        vector<int> psum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    psum[j] = psum[j] + 1;
                else
                    psum[j] = 0;
            }
            maxxAre = max(maxxAre, largestArea(psum));
        }

        return maxxAre;
    }
};