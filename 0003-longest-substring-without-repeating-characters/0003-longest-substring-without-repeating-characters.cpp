class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_set<char> store;

        for(int right=0; right<s.size(); right++){
            while(store.count(s[right])){
                store.erase(s[left]);
                left++;
            }
            store.insert(s[right]);

            maxLen = max(maxLen, right- left+ 1);
        }

        return maxLen;
    }
};