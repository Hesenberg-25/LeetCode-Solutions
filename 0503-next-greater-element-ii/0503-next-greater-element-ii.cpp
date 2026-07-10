class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge2(n); 
        stack<int> st;
        
        for (int i = (2 * n) - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            
            if (i < n) {
                if (st.empty()) {
                    nge2[i] = -1;
                } else {
                    nge2[i] = st.top();
                }
            }
            
            st.push(nums[i % n]);
        }
        
        return nge2;
    }
};