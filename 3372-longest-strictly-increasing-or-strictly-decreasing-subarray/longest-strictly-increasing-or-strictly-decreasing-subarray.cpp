class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res=1,n=nums.size(),i=0;

        //strictly increasing
        while(i<n)
        {
            int cnt=1;
            while(i+1<n && nums[i]<nums[i+1])
            {
                i++;
                cnt++;
            }

            res=max(res,cnt);
            i++;
        }

        //strictly decreasing
        i=0;
        while(i<n)
        {
            int cnt=1;
            while(i+1<n && nums[i]>nums[i+1])
            {
                i++;
                cnt++;
            }

            res=max(res,cnt);
            i++;
        }

        return res;
    }
};