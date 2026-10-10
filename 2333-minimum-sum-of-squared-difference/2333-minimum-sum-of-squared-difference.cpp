class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        long long total_diff = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total_diff += diff[i];
        }

        if (total_diff <= k) return 0;

        sort(diff.rbegin(), diff.rend());
        diff.push_back(0);

        for (int i = 0; i < n; i++) {
            long long count = i + 1;
            long long gap = diff[i] - diff[i + 1];

            if (gap == 0) continue;

            long long needed = count * gap;

            if (k >= needed) {
                k -= needed;
            } else {
                int subtract_all = k / count;
                int remainder = k % count;

                int target_val = diff[i] - subtract_all;

                for (int j = 0; j <= i; j++) {
                    if (j < remainder) {
                        diff[j] = target_val - 1;
                    } else {
                        diff[j] = target_val;
                    }
                }
                k = 0;
                break;
            }

            for (int j = 0; j <= i; j++) {
                diff[j] = diff[i + 1];
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * diff[i] * diff[i];
        }

        return ans;
    }
};