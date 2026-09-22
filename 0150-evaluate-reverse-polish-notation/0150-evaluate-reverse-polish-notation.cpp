class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long val2 = st.top();
                st.pop();
                long long val1 = st.top();
                st.pop();

                if (token == "+") st.push(val1 + val2);
                else if (token == "-") st.push(val1 - val2);
                else if (token == "*") st.push(val1 * val2);
                else if (token == "/") st.push(val1 / val2);
            } else {
                st.push(stoll(token));
            }
        }

        return st.top();
    }
};