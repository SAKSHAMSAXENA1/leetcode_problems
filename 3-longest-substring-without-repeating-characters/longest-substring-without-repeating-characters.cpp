class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i=0;i<256;i++) hash[i]=-1; // last seen index of each char is -1

        int l=0,r=0,n=s.size(),maxLen=0;
        while(r<n)
        {
            if(hash[s[r]]!=-1)//last seen index of char is not -1,i.e the char is seen previously
            {
                if(l<=hash[s[r]]) // if the char is already seen in the window being considered
                {
                    l=hash[s[r]]+1; // to make the current window duplicate free
                }
            }

            maxLen=max(maxLen,r-l+1);
            hash[s[r]]=r; // update the last seen index of this char
            r++;
        }

        return maxLen;
    }
};