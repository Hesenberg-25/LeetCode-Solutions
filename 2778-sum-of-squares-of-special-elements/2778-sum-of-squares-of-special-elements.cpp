class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int till = nums.size();
        int ans = 0;

        for(int i=1; i<=till/2; i++){
            if((till % i) == 0){
                ans+=(pow(nums[i-1], 2));
            }
        }

        ans+=(pow(nums[till-1], 2));
        return ans;
    }
};