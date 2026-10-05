class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> store;
        store.push(0);

        for(char c : s){
            if(c=='(') store.push(0);

            else{
                int topStore = store.top();
                store.pop();

                store.top() += max(2 * topStore, 1);
            }
        }

        return store.top();
    }
};