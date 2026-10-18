class Solution {
public:
    void create(int start, int max, int sized, vector<int>& part, vector<vector<int>>& ans){
        if(part.size() == sized){
            ans.push_back(part);  
            return;
        }

        for(int i=start; i <= max - (sized - (int)part.size()) + 1; i++){
            part.push_back(i);
            create(i+1, max, sized, part, ans);
            part.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> part;
        create(1, n, k, part, ans);
        return ans;
    }
};