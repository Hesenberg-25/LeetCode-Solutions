class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> store;
        for(char str : s){
            if(str == ')'){
                string rev="";
                while(!store.empty() && store.top()!='('){
                    rev += store.top();
                    store.pop();
                }
                if(!store.empty() && store.top() == '(') store.pop();

                for(char  c : rev){
                    store.push(c);
                }
            }
            else{
                store.push(str);
            }
        }

        string ans="";
        while(!store.empty()){
            ans+=store.top();
            store.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};