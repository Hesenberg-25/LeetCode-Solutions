class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = 0;
        for(int v : nums){
            if(v > max) max = v;
        }

        int ans = 0;
        for(int v : nums){
            ans+=(max - v);
        }

        return ans;
    }
};