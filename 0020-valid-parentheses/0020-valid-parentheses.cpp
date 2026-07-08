class Solution {
public:
    bool isValid(string s) {
        stack<char> para;
        
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                para.push(ch);
            } else {
                if (para.empty()) {
                    return false;
                }
                
                if (ch == ')' && para.top() != '(') {
                    return false;
                } else if (ch == '}' && para.top() != '{') {
                    return false;
                } else if (ch == ']' && para.top() != '[') {
                    return false;
                } else {
                    para.pop();
                }
            }
        }
        
        return para.empty();
    }
};