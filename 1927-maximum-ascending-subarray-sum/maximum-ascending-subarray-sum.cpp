class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size(),i=0,res=0;

        while(i<n)
        {
            int sum=nums[i];
            while(i+1<n && nums[i]<nums[i+1])
            {
                sum+=nums[i+1];
                i++;
            }

            res=max(res,sum);
            i++;
        }

        return res;
    }
};