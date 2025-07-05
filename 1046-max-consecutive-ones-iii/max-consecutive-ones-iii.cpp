class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0,r=0,l=0,n=nums.size(),ones=0;

        while(r<n)
        {
            ones+=nums[r]; // acquire

            // while the condn of probm: no of flips<=k is false
            while(r-l+1 - ones > k) // flips=tot elements - ones
            {
                ones-=nums[l]; // release;
                l++; // shrink the window (release)
            }

            // now condn of probm: flips<=k is true, so update the answer
            res=max(res,r-l+1);
            r++; // expand the window (acquire)
        }

        return res;
    }
};