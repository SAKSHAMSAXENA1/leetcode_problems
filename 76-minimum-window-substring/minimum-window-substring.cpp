class Solution {
public:
bool windowContainsT(unordered_map<char,int> &uS,unordered_map<char,int> &uT)
{
    for(auto it:uT)
    {
        // it=<char,freq>
        if(uS[it.first]<it.second) return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        unordered_map<char,int> uT,uS;
        int l=0,r=0,n=s.size(),minLen=INT_MAX;
        int ansL=-1,ansR=-1;

        for(auto it:t) uT[it]++;

        while(r<n)
        {
            uS[s[r]]++; // (acquire)

            while(windowContainsT(uS,uT))
            {
                if(r-l+1<minLen)
                {
                    minLen=r-l+1;
                    ansR=r;
                    ansL=l;
                }
                //minLen=min(minLen,r-l+1);
                
                uS[s[l]]--; // (release)
                l++; // shrink the window (release)
            }

            // now the window does not contain t,so expand the window
            r++; // expand the window (acquire)
        }

        if(minLen==INT_MAX) return ""; // whole of s does not contain t
        return s.substr(ansL,ansR-ansL+1);
    }
};