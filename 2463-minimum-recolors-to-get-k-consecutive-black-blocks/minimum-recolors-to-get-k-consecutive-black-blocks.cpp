class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size(),wCnt=0,mini=INT_MAX,i=0;
        for(;i<k;i++)
        {
            if(blocks[i]=='W') wCnt++;
            //else bCnt++;
        }

        for(;i<n;i++)
        {
            mini=min(mini,wCnt);

            // release
            if(blocks[i-k]=='W') wCnt--;
            
            // acquire
            if(blocks[i]=='W') wCnt++;
        }

        mini=min(mini,wCnt);
        return mini;
    }
};