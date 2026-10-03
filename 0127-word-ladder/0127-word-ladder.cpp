class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if(words.count(endWord) == 0) return 0;

        queue<pair<string, int>> store;
        store.push({beginWord, 1});

        words.erase(beginWord);

        while(!store.empty()){
            string word = store.front().first;
            int nPath = store.front().second;
            store.pop();

            if(word == endWord) return nPath; 

            for(int i=0; i<word.size(); i++){
                char og = word[i];

                for(char c='a'; c<='z'; c++){
                    word[i]=c;
                    if(words.count(word)){
                        words.erase(word);
                        store.push({word, nPath+1});
                    }
                }
                word[i]=og;
            }
        }
        return 0;
    }
};