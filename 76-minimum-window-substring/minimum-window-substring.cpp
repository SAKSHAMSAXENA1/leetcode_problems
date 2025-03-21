class Solution {
public:
bool windowContainsT(int uS[],int uT[])
{
    for(int i=0;i<52;i++)
    {
        if(uS[i]<uT[i]) return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        int uS[52]={0},uT[52]={0};
        int l=0,r=0,n=s.size(),minLen=INT_MAX;
        int ansL=-1,ansR=-1;

        for(auto it:t)
        {
            if('a'<=it) uT[it-'a'+26]++;
            else uT[it-'A']++;
        }

        while(r<n)
        {
            if('a'<=s[r]) uS[s[r]-'a'+26]++; // (acquire)
            else uS[s[r]-'A']++; // (acquire)

            while(windowContainsT(uS,uT))
            {
                if(r-l+1<minLen)
                {
                    minLen=r-l+1;
                    ansR=r;
                    ansL=l;
                }
                //minLen=min(minLen,r-l+1);
                
                if('a'<=s[l]) uS[s[l]-'a'+26]--; // (release)
                else uS[s[l]-'A']--; // (release)
                l++; // shrink the window (release)
            }

            // now the window does not contain t,so expand the window
            r++; // expand the window (acquire)
        }

        if(minLen==INT_MAX) return ""; // whole of s does not contain t
        return s.substr(ansL,ansR-ansL+1);
    }
};