class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> store;
        for(int num : nums){
            store.insert(num);
        }
        int i=1;
        while(true){
            if(store.count(k*i)) i++;
            else return k*i;
        }
    }
};