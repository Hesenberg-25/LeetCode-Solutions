class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int median = nums[nums.size() / 2];
        int steps = 0;
        
        for (int val : nums) {
            steps += abs(val - median);
        }
        
        return steps;
    }
};