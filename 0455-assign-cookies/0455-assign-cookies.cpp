class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int final = 0;
        int cookieIndex = 0;
        while (cookieIndex < s.size() && final < g.size()) {
            if (s[cookieIndex] >= g[final]) {
                final++;
            }
            cookieIndex++;
        }
        return final;
    }
};