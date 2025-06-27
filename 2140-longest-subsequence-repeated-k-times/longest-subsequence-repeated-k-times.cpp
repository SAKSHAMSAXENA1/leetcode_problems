class Solution {
public:
bool isRepeatedKTimes(string &ds,string &s,int &k)
{
    int n=s.size(),m=ds.size(),i=0,j=0,cnt=0;

    while(i<n)
    {
        if(s[i]==ds[j])
        {
            j++;
            if(j==m)
            {
                j=0;
                cnt++;
            }
        }

        i++;
    }

    return cnt>=k;
}

void generateSubsequences(string &ds,vector<bool> &canUse,vector<int> &remCharFreqPerSubsequence,
int &maxLen,string &res,string &s,int &k)
{
    if(ds.size()>maxLen) return;

    if(ds.size()>res.size() || (ds.size()==res.size() && ds>res))
    {
        if(isRepeatedKTimes(ds,s,k))
        res=ds;
    }

    for(int i=0;i<26;i++)
    {
        if(canUse[i]==false || remCharFreqPerSubsequence[i]==0) continue;

        ds.push_back(i+'a');
        remCharFreqPerSubsequence[i]--;

        generateSubsequences(ds,canUse,remCharFreqPerSubsequence,maxLen,res,s,k);

        // backtrack
        ds.pop_back();
        remCharFreqPerSubsequence[i]++;
    }
}
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size(),maxLen=n/k;
        vector<int> freq(26,0);

        for(auto it:s)
        freq[it-'a']++;

        vector<bool> canUse(26,false);
        vector<int> charFreqPerSubsq(26,0);

        for(int i=0;i<26;i++)
        {
            if(freq[i]>=k)
            {
                canUse[i]=true;
                charFreqPerSubsq[i]=freq[i]/k;
            }
        }

        string res="",subsequence="";

        generateSubsequences(subsequence,canUse,charFreqPerSubsq,maxLen,res,s,k);

        return res;
    }
};