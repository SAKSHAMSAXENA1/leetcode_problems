class Solution {
public:
    bool isPresent(string &it, string &word,int &n)
    {
        int m=word.size();

        if(n>m) return false;

        for(int i=0;i<m;i++)
        {
            int temp=i,j;
            for(j=0;j<n && temp<m;j++)
            {
                if(it[j]!=word[temp]) break;
                temp++;
            }

            if(j==n) return true;
        }

        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;

        for(auto it:words)
        {
            int n=it.size();
            for(auto word:words)
            {
                if(it==word) continue;
                
                if(isPresent(it,word,n))
                {
                    res.push_back(it);
                    break;
                } 
            }
        }

        return res;
    }
};