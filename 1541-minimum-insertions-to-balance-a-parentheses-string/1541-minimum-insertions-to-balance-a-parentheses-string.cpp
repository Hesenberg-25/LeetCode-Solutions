class Solution {
public:
    int minInsertions(string s) {
        int neededC = 0;
        int insertO = 0;

        for(char c : s){
            if(c=='('){
                if(neededC % 2 == 1){
                    insertO++;
                    neededC--;
                }
                neededC+=2;
            }
            else{
                neededC--;

                if(neededC < 0){
                    insertO++;
                    neededC+=2;
                }
            }
        }

        return neededC + insertO;
    }
};