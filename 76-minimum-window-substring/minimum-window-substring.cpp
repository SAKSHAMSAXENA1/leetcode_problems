class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size(),l=0,r=0,minLen=INT_MAX;
        int startIndex=-1,cntOfMatchedChar=0;
        int u[256]={0}; // hashmap to store freq of each char

        for(auto it:t) u[it]++;

        while(r<m)
        {
            if(u[s[r]]>0) cntOfMatchedChar++;
            u[s[r]]--; // (acquire)

            while(cntOfMatchedChar==n) // while the window/substring contains t, shrink the 
            {                       // window to get such shortest valid window containing t
                if(r-l+1<minLen) // update the minLen
                {
                    minLen=r-l+1;
                    startIndex=l;
                }

                u[s[l]]++; // (release)
                if(u[s[l]]>0) cntOfMatchedChar--;
                
                l++; // shrink the window (release)
            }

            // now the count of matched char is <n, so expand the window to acquire more char
            // to match
            r++; // expand the window (acquire)
        }

        if(startIndex==-1) return "";
        return s.substr(startIndex,minLen);
    }
};