class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> store;

        for(const auto& interval : intervals){
            int start = interval[0];
            int end = interval[1];

            if(!store.empty() && store.top() < start){
                store.pop();
            }

            store.push(end);
        }

        return store.size();
    }
};