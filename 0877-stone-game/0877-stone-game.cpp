class Solution {
private:
    int memo[500][500];

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
    bool stoneGame(vector<int>& piles) {
        memset(memo, -1, sizeof(memo));
        return getMaxScoreDiff(piles, 0, piles.size() - 1) >= 0;
    }
};