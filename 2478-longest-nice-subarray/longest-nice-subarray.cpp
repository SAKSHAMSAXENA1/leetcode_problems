class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,r=0,n=nums.size(),maxLen=0,mask=0;

        while(r<n)
        {
            while((mask & nums[r])!=0) // while the condn of probm is false
            {
                mask=mask ^ nums[l]; // (release)
                l++; // shrink the window (release)
            }

            // now (mask & nums[r])==0, i.e condn of probm is satisfied, so update maxLen
            maxLen=max(maxLen,r-l+1);

            mask=mask | nums[r]; // (acquire)-> nums[r] is part of the window now, so 
            // include it in mask
            r++; // expand the window (acquire)
        }

        return maxLen;
    }
};