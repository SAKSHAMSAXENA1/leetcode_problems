class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> uc(26,0),lc(26,0);
        int cnt = 0;

        for(auto &it:word)
        {
            if('a'<=it && it<='z') // lowercase
            {
                if(lc[it-'a']==-1) continue;

                if(uc[it-'a'] == 1) // uppercase already exists
                {
                    uc[it-'a'] = lc[it-'a'] = -1;
                }
                else // uppercase doesn't already exist
                lc[it-'a'] = 1;
            }
            else // uppercase
            {
                if(lc[it-'A'] == 1) // lowercase already exists
                uc[it-'A'] = 1;
                else 
                uc[it-'A'] = lc[it-'A'] = -1;
            }
        }

        for(int i = 0;i<26;i++)
        cnt+= (uc[i]==1 && lc[i]==1);

        return cnt;
    }

};