class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> atLast(3, -1);
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            atLast[s[i] - 'a'] = i;

            if (atLast[0] != -1 && atLast[1] != -1 && atLast[2] != -1) {
                int minIndex = min({atLast[0], atLast[1], atLast[2]});
                count += (minIndex + 1);
            }
        }

        return count;
    }
};