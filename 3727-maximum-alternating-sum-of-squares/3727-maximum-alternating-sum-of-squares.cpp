class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        int start = 0;
        int end = nums.size() - 1;
        long long ans = 0;
        bool sign = true;

        while (start <= end) {
            if (sign) {
                ans += (long long)nums[end] * nums[end];
                end--;
            } else {
                ans -= (long long)nums[start] * nums[start];
                start++;
            }
            sign = !sign;
        }

        return ans;
    }
};