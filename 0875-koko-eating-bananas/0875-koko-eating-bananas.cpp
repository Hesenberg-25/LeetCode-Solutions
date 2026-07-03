class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxs = piles[0];
        for (int x : piles) {
            maxs = max(maxs, x);
        }

        int low = 1;
        int high = maxs;
        int result = maxs;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long calhrs = 0;

            for (int x : piles) {
                calhrs += (x + mid - 1) / mid;
            }

            if (calhrs <= h) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};