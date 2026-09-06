class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int open=0;
        int close=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*'){
                open++;
            }
            else{
                open--;
            }

            if(s[n-i-1]==')' || s[n-i-1]=='*'){
                close++;
            }
            else{
                close--;
            }
            if(open<0 || close<0) return false;
        }
        return true;
    }
};