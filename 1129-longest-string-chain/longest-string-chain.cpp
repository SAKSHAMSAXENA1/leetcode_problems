class Solution {
public:
bool isPredecessor(string &a, string &b)
{
    int n=a.size(),m=b.size();
    if(n>=m) return false;
    int i=0,j=0,misMatch=0;

    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            i++;
        }
        else
        {
            misMatch++;
        } 
        j++;
    }

    while(j<m)
    {
        misMatch++;
        j++;
    }

    return misMatch==1;
}

    int longestStrChain(vector<string>& words) {
        int n=words.size(),maxi=1;
        vector<int> dp(n,1);
        auto comp=[&] (string a,string b)
        {
            return a.size()<b.size();
        };

        sort(words.begin(),words.end(),comp);

        for(auto it:words)
        cout<<it<<" ";
        cout<<endl;

        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(isPredecessor(words[prev],words[i]) && dp[prev]+1>dp[i])
                {
                    dp[i]=dp[prev]+1;
                }
            }

            maxi=max(maxi,dp[i]);
        }

        return maxi;
    }
};