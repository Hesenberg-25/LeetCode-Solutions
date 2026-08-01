class Solution {
private:
    int memo[21][21];

    int getMaxScoreDiff(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        int pickLeft = nums[left] - getMaxScoreDiff(nums, left + 1, right);
        int pickRight = nums[right] - getMaxScoreDiff(nums, left, right - 1);

        return memo[left][right] = max(pickLeft, pickRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return getMaxScoreDiff(nums, 0, nums.size() - 1) >= 0;
    }
};