class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ansSize=nums1.size() + nums2.size();

        nums1.reserve(ansSize);
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        sort(nums1.begin(),nums1.end());

        double median;
        if (ansSize % 2 == 0) {
            median = (nums1[ansSize / 2 - 1] + nums1[ansSize / 2]) / 2.0;
        }
        else{
            median = nums1[ansSize / 2];
        }
        return median;
    }
};