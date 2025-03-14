class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // longest window/subarray containing at most k 0's
        int l=0,r=0,n=nums.size(),maxLen=0;
        int cntOfZeros=0;

        while(r<n)
        {
            cntOfZeros+=(nums[r]==0); // (acquire)

            if(cntOfZeros>k)
            {
                cntOfZeros-=(nums[l]==0); // (release)
                l++; // shrink the window (release)
            }

            // update maxLen only when the window has <=k 0's
            if(cntOfZeros<=k)
            maxLen=max(maxLen,r-l+1);

            r++; // expand the window (acquire)
        }

        return maxLen;
    }
};