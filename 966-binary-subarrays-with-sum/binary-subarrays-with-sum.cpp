class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0,r=0,n=nums.size(),prefixZeros=0,cnt=0,sum=0;

        while(r<n)
        {
            sum+=nums[r]; // (acquire)

            while(l<r && (nums[l]==0 || sum>goal))
            {
                if(nums[l]==0) prefixZeros++;
                else prefixZeros=0;

                sum-=nums[l]; // (release)
                l++; // shrink the window (release)
            }

            if(sum==goal) 
            cnt+=1+prefixZeros;

            r++; // expand the window (acquire)
        }

        return cnt;
    }
};