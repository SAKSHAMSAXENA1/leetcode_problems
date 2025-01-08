class Solution {
public:
    bool isPrefixAndSuffix(string &str1, string &str2)
    {
        int n=str1.size(),m=str2.size();
        if(n>m) return false;
        for(int i=0,j=0;i<n && j<m;i++,j++)
        if(str1[i]!=str2[j]) return false;

        for(int i=n-1,j=m-1;i>=0 && j>=0;i--,j--)
        if(str1[i]!=str2[j]) return false;

        return true;
    } 
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(),res=0;
        for(int j=1;j<n;j++)
        {
            for(int i=0;i<j;i++)
            res+=(int)isPrefixAndSuffix(words[i], words[j]);
        }

        return res;
    }
};