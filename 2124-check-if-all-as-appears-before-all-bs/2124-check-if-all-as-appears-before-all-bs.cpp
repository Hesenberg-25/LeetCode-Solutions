class Solution {
public:
    bool checkString(string s) {
        bool app = false;
        for(char c : s){
            if(c == 'b'){
                app = true;
            }
            if(app == true && c == 'a') return false;
        }
        return true;
    }
};