class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size(),maxLen=1,maxIndex=0;
        vector<int> dp(n,1),hash(n);
        vector<string> res;

        for(int i=0;i<n;i++) hash[i]=i;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(groups[i]!=groups[j] && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                    if(dp[i]>maxLen)
                    {
                        maxLen=dp[i];
                        maxIndex=i;
                    }
                }
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