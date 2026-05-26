class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> uc(26,false),lc(26,false);
        int cnt = 0;

        for(auto &it : word)
        {
            if('a'<=it && it<='z') 
            lc[it-'a']=true;
            else
            uc[it-'A']=true;
        }

        for(int i = 0;i <26;i++)
        cnt+=lc[i] & uc[i];

        return cnt;
    }
};