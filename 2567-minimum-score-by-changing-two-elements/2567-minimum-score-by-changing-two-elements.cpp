class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int dropTwoSmallest = nums[n - 1] - nums[2];
        int dropTwoLargest = nums[n - 3] - nums[0];
        int dropOneEach = nums[n - 2] - nums[1];

        return min({dropTwoSmallest, dropTwoLargest, dropOneEach});
    }
};