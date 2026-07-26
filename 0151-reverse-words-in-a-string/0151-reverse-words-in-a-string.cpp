class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string v = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                v.insert(0, 1, s[i]);
            } else {
                if (!v.empty()) {   
                    words.push_back(v);
                    v = "";
                }
            }
        }

        if (!v.empty()) {
            words.push_back(v);
        }

        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1) {
                ans += " ";
            }
        }

        return ans;
    }
};