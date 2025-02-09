class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        int wordLength=beginWord.size();
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty())
        {
            string curWord=q.front().first;
            int curLevel=q.front().second;
            q.pop();

            if(curWord==endWord) return curLevel;

            for(int i=0;i<wordLength;i++)
            {
                char original=curWord[i];

                for(char c='a';c<='z';c++)
                {
                    curWord[i]=c;

                    if(st.find(curWord)!=st.end())
                    {
                        q.push({curWord,curLevel+1});
                        st.erase(curWord);
                    }
                }

                curWord[i]=original;
            }
        }

    return 0;
    }
};