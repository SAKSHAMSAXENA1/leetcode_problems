class Solution {
public:
unordered_map<string,int> u;
vector<vector<string>> res;
string bW;
int wordLength;

void dfs(string &word, vector<string> &sequence)
{
    if(word==bW)
    {
        reverse(sequence.begin(),sequence.end());
        res.push_back(sequence);
        reverse(sequence.begin(),sequence.end());
        return;
    }

    int curLevel=u[word];

    for(int i=0;i<wordLength;i++)
    {
        char original=word[i];

        for(char c='a';c<='z';c++)
        {
            word[i]=c;

            if(u.find(word)!=u.end() && u[word]==curLevel-1)
            {
                sequence.push_back(word);
                dfs(word,sequence);
                sequence.pop_back();
            }
        }
        word[i]=original;
    }
}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        wordLength=beginWord.size();
        bW=beginWord;
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        u[beginWord]=0;

        while(!q.empty())
        {
            string curWord=q.front();
            q.pop();

            if(curWord==endWord) break;

            int curLevel=u[curWord];

            for(int i=0;i<wordLength;i++)
            {
                char original=curWord[i];

                for(char c='a';c<='z';c++)
                {
                    curWord[i]=c;
                    if(st.find(curWord)!=st.end())
                    {
                        q.push(curWord);
                        u[curWord]=curLevel+1;
                        st.erase(curWord);
                    }
                }

                curWord[i]=original;
            }
        }

        if(u.find(endWord)!=u.end())
        {
            vector<string> sequence;
            sequence.push_back(endWord);
            dfs(endWord,sequence);
        } 
        
        return res;
    }
};