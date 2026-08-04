class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int idx=0;
        int currexpect=nums[0];
        int maxed=nums[nums.size()-1];
        while(currexpect<=maxed){
            if(nums[idx]==currexpect){
                while(idx<nums.size()-1 && nums[idx]==currexpect){
                    idx++;
                }
            }
            else{
                ans.push_back(currexpect);
            }
            currexpect++;
        }
        return ans;
    }
};