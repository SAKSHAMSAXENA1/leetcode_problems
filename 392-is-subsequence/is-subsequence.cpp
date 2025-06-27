class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0,m=t.size(),n=s.size(); 

        while(i<m && j<n)
        {
            if(t[i]==s[j])
                j++;

            i++;
        }

        return j==n;
    }
};