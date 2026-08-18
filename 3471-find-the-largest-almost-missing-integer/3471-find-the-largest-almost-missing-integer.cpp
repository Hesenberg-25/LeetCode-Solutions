class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mode;

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> uniqueInWindow;
            for (int j = i; j < i + k; j++) {
                uniqueInWindow.insert(nums[j]);
            }
            for (int val : uniqueInWindow) {
                mode[val]++;
            }
        }

        int maxVal = -1;
        for (const auto& [val, count] : mode) {
            if (count == 1) {
                maxVal = max(maxVal, val);
            }
        }

        return maxVal;
    }
};