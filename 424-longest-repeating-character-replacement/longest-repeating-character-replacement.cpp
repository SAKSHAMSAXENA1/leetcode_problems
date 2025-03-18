class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.size(),maxLen=0,maxf=0;
        int hash[26]={0};

        while(r<n)
        {
            hash[s[r]-'A']++; // (acquire)
            maxf=max(maxf,hash[s[r]-'A']);

            // conversions req=len-maxf=(r-l+1)-maxf

            while((r-l+1)-maxf>k) // while conversions req >k,i.e condn of problem is false
            {
                hash[s[l]-'A']--; // (release)

                maxf=0;
                for(int i=0;i<26;i++) maxf=max(maxf,hash[i]); // reupdate maxf while shrinking

                l++; // shrink the window (release)
            }

            // now the window has conversions req<=k , i.e. window is valid, so update maxLen
            maxLen=max(maxLen,r-l+1);
            r++; // expand the window (acquire)
        }

        return maxLen;
    }
};