class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> ngeMap;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int ele = nums2[i];
            
            while (!st.empty() && st.top() <= ele) {
                st.pop();
            }
            
            if (st.empty()) {
                ngeMap[ele] = -1;
            } else {
                ngeMap[ele] = st.top();
            }
            
            st.push(ele);
        }
        
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(ngeMap[num]);
        }
        
        return ans;
    }
};