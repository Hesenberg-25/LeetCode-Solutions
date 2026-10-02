class Solution {
private:
    void generate(int open, int close, string &para, int n, vector<string> &ans)
    {
        if (para.size() == (2 * n))
        {
            ans.push_back(para);
            return;
        }
        if (open < n)
        {
            para.push_back('(');
            generate(open + 1, close, para, n, ans);
            para.pop_back();
        }
        if (close < open)
        {
            para.push_back(')');
            generate(open, close + 1, para, n, ans);
            para.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string para = "";
        generate(0, 0, para, n, ans);
        return ans;
    }
};