class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_set<int> store;
            for(int j=i; j<n; j++){
                store.insert(nums[j]);
                ans+=(store.size()*store.size());
            }
        }
        return ans;
    }
};