class Solution {
public:
    int minAddToMakeValid(string s) {
        int closeBark = 0;
        int openBark = 0;
        if(s.size() == 0) return 0;

        for(char c : s){
            if(c == '(') openBark++;
            else{
                if(openBark>0) openBark--;
                else closeBark++;
            }
        }

        return openBark + closeBark;
    }
};