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

bool canGenerateSubsequences(string &ds, vector<int> &remCharFreqPerSubsequence, int &maxLen,
string &res,string &s,int &k)
{
    if(ds.size()>maxLen) return false;

    if(ds.size()==maxLen)
    {
        if(isRepeatedKTimes(ds,s,k))
        {
            res=ds;
            return true;
        }
    }

    for(int i=25;i>=0;i--)
    {
        if(remCharFreqPerSubsequence[i]==0) continue;

        ds.push_back(i+'a');
        remCharFreqPerSubsequence[i]--;

        if(canGenerateSubsequences(ds,remCharFreqPerSubsequence,maxLen,res,s,k))
        return true;

        // backtrack
        ds.pop_back();
        remCharFreqPerSubsequence[i]++;
    }

    return false;
}
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size(),maxLen=n/k;
        vector<int> freq(26,0);

        for(auto it:s)
        freq[it-'a']++;

        vector<int> charFreqPerSubsq(26,0);

        for(int i=0;i<26;i++)
        {
            charFreqPerSubsq[i]=freq[i]/k;
        }

        string res="";

        for(int subsequenceLen=maxLen;subsequenceLen>=0;subsequenceLen--)
        {
            string cur="";
            if(canGenerateSubsequences(cur,charFreqPerSubsq,subsequenceLen,res,s,k))
            break;
        }
        
        return res;
    }
};