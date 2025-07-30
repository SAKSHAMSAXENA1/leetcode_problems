class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0,res=0,n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]>=maxi)
            {
                int j=i+1;

                while(j<n && nums[i]==nums[j])
                j++;

                if(nums[i]>maxi)
                res=j-i;
                else // nums[i]==maxi
                res=max(res,j-i);

                maxi=nums[i];
                i=j-1;
            }
        }

        return res;
    }
};