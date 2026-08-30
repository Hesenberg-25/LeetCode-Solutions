class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int mini = 0, maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < nums[mini]) mini = i;
            if(nums[i] > nums[maxi]) maxi = i;
        }
        
        int Left = min(mini, maxi);
        int Right = max(mini, maxi);

        int bothF = Right + 1;
        int bothB = n - Left;
        int Sep = Left + 1 + n - Right;

        return min({bothF, bothB, Sep});
    }
};