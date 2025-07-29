class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int r=0,l=0,n=nums.size(),minLen=n,curOr=0,m=0;

        vector<int> maxOr(n,0);
        maxOr[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        maxOr[i]=maxOr[i+1] | nums[i];

        for(auto it:maxOr) 
        cout<<it<<" ";

        int totOr=maxOr[0];

        /*if(maxOr==0) // all elements of nums are zero
        return ; // non-empty single element zero*/

        int temp=totOr;

        while(temp)
        {
            m++;
            temp/=2;
        }

        vector<int> freq(m,0),res(n,0);

        while(r<n)
        {
            curOr |=nums[r]; // acquire

            int temp=nums[r],j=m-1;

            while(temp)
            {
                int dig=temp%2;

                if(dig==1)
                freq[j]++; // acquire

                j--;
                temp/=2;
            }

            // while curOr==maxOr, keep shrinking the window
            while(l<=r && curOr==maxOr[l])
            {
                minLen=min(minLen,r-l+1); // since curOr==maxOr, update the minLen
                res[l]=r-l+1;

                int c=nums[l];
                int j=m-1;

                // remove contribution of nums[l] from freq
                // (release)
                while(c)
                {
                    int dig=c%2;

                    if(dig==1) // some other nums[i] may also be responsible for set bit
                    freq[j]--; // (release)
    
                    j--;
                    c/=2;
                }
                
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