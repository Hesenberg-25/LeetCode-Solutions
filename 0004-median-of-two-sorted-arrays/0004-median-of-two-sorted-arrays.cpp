class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1size = nums1.size();
        int nums2size = nums2.size();
        int ansSize = nums1size + nums2size;
        vector<int> ans;
        
        int nums1counter = 0;
        int nums2counter = 0;
        
        while (nums1counter < nums1size && nums2counter < nums2size) {
            if (nums1[nums1counter] > nums2[nums2counter]) {
                ans.push_back(nums2[nums2counter]);
                nums2counter++;
            } else {
                ans.push_back(nums1[nums1counter]);
                nums1counter++;
            }
        }
        
        while (nums1counter < nums1size) {
            ans.push_back(nums1[nums1counter]);
            nums1counter++;
        }
        
        while (nums2counter < nums2size) {
            ans.push_back(nums2[nums2counter]);
            nums2counter++;
        }
        
        double median;
        if (ansSize % 2 == 0) {
            median = (ans[ansSize / 2 - 1] + ans[ansSize / 2]) / 2.0;
        } else {
            median = ans[ansSize / 2];
        }

        return median;
    }
};