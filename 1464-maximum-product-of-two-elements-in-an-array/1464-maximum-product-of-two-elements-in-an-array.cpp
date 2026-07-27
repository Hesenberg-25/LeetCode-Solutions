class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sized=nums.size();
        return (nums[sized-1]-1)*(nums[sized-2]-1);
    }
};