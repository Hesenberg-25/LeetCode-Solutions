class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        vector<int> nse(n, n), psee(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) psee[i] = st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        vector<int> nge(n, n), pgee(n, -1);
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nge[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) pgee[i] = st.top();
            st.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            long long left_min = i - psee[i];
            long long right_min = nse[i] - i;
            long long left_max = i - pgee[i];
            long long right_max = nge[i] - i;
            
            long long max_contribution = left_max * right_max * nums[i];
            long long min_contribution = left_min * right_min * nums[i];
            
            sum += (max_contribution - min_contribution);
        }
        
        return sum;
    }
};