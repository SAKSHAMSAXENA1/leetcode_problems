class Solution {
public:
void updateFreqContribution(int freq[],int temp,int change)
{
    int j=31; // j=m-1, and m=freq.size()=32, so j=32-1=31
    while(temp)
    {
        int dig=temp%2;

        if(dig==1)
        freq[j]=freq[j]+change; // change can be +1(acquire) or -1(release)

        temp/=2;
        j--;
    }
}
    vector<int> smallestSubarrays(vector<int>& nums) {
        int r=0,l=0,n=nums.size(),curOr=0;

        vector<int> maxOr(n,0);
        maxOr[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        maxOr[i]=maxOr[i+1] | nums[i];

        /*int totOr=maxOr[0],m=0;

        /while(totOr)
        {
            m++;
            totOr=2;
        }*/
        int m=32;

        vector<int> res(n,0);
        int freq[32]={0};

        while(r<n)
        {
            curOr |=nums[r]; // acquire
            updateFreqContribution(freq,nums[r],+1); // (+1 : acquire)

            // while curOr==maxOr, keep shrinking the window
            while(l<=r && curOr==maxOr[l])
            {
                // since curOr==maxOr, update the minLen
                res[l]=r-l+1;

                // remove contribution of nums[l] from freq
                // (release)
                updateFreqContribution(freq,nums[l],-1); // (-1: release)
                
                curOr=0;
                for(auto it:freq)
                {
                    //if(it>0) // some other nums[i] may also be responsible for set bit
                    curOr=curOr*2+(it>0);
                }

                l++; // shrink the window (release)
            }

            // now curOr<maxOr i.e. condn of probm is false, or not satisfied
            // so expand the window
            r++; // expand the window (acquire)
        }

        return res;
    }
};