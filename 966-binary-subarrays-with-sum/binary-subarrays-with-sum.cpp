class Solution {
public:
    int f(vector<int> &nums, int goal)
    {
        // cnt of subarrays whose sum<=goal
        if(goal<0) return 0;
        int l=0,r=0,n=nums.size(),cnt=0,sum=0;

        while(r<n)
        {
            sum+=nums[r]; // (acquire)

            while(sum>goal) 
            {
                sum-=nums[l]; // (release)
                l++; // shrink the window (release)
            }

            // now sum of subarray/window <=goal
            cnt+=r-l+1;
            r++; // expand the window (acquire)
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal)-f(nums,goal-1);
    }
};