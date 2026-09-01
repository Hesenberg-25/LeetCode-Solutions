class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> store;
        for(int num : nums){
            store[num]++;
        }
        priority_queue<pair<int,int>> MaxHeap;
        for(auto ele : store){
            MaxHeap.push({ele.second,ele.first});
        }
        while(k>0){
            ans.push_back(MaxHeap.top().second);
            MaxHeap.pop();
            k--;
        }
        return ans;
    }
};