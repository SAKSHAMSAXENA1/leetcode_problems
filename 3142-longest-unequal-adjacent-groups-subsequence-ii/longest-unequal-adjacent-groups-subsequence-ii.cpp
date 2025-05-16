class Solution {
public:
int isHammingDistance1(string &a,string &b)
{
    int diffChar=0,n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            diffChar++;
            if(diffChar>1) return false;
        }
    }

    // diffChar<=1
    return diffChar==1;
}
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
       int n=words.size(),maxLen=0,maxIndex=-1;
       vector<int> dp(n,1),hash(n);
       vector<string> res;
       for(int i=0;i<n;i++) hash[i]=i;

       for(int i=0;i<n;i++) 
       {
            for(int j=0;j<i;j++)
            {
                if(words[j].size()==words[i].size() && groups[j]!=groups[i]
                && isHammingDistance1(words[j],words[i]) && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }

            if(dp[i]>maxLen)
            {
                maxLen=dp[i];
                maxIndex=i;
            }
       }

       int i=maxIndex;
       while(i!=hash[i])
       {
            res.push_back(words[i]);
            i=hash[i];
       }
       res.push_back(words[i]);

       reverse(res.begin(),res.end());
       return res;
    }
};