class Solution {
public:
    string makeFancyString(string s) {
        int slow = 0;
        for(int fast=0; fast<s.size(); fast++){
            if(slow>=2 && s[fast]==s[slow-1] && s[fast]==s[slow-2]){
                continue;
            }
            s[slow] = s[fast];
            slow++;
        }
        s.resize(slow);
        return s;
    }
};