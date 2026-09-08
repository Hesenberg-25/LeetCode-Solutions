class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int IndexMax = 0;
        for(int i=0; i<n; i++){
            if(i>IndexMax) return false;

            IndexMax=max(IndexMax , i+nums[i]);
        }
        return true;
    }
};