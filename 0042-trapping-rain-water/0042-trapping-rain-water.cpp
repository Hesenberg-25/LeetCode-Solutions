class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int underWater = 0;
        vector<int> preMax(n);
        vector<int> subMax(n);

        preMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], height[i]);
        }

        subMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            subMax[i] = max(subMax[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            underWater += min(preMax[i], subMax[i]) - height[i];
        }

        return underWater;
    }
};