class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = ""; 
        
        for (char ele : num) {
            while (!res.empty() && k > 0 && res.back() > ele) {
                res.pop_back();
                k--;
            }
            
            if (!res.empty() || ele != '0') {
                res.push_back(ele);
            }
        }
        
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }
        
        return res.empty() ? "0" : res;
    }
};