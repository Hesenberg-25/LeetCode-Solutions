class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        vector<int> psee(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        long long sum = 0;
        long long mod = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            long long conti = (left * right) % mod;
            long long totalProduct = (arr[i] * conti) % mod;

            sum = (sum + totalProduct) % mod;
        }
        return sum;
    }
};