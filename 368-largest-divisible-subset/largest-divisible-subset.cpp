class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),lastIndex=0,maxi=0;
        vector<int> dp(n,1),divisor(n,0),res;
        sort(nums.begin(),nums.end());        

        for(int i=1;i<n;i++)
        {
            divisor[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        divisor[i]=j;
                    }
                }
            }

            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastIndex=i;
            }
        }

        int i=lastIndex;
        while(divisor[i]!=i)
        {
            res.push_back(nums[i]);
            i=divisor[i];
        }
        res.push_back(nums[i]);
        reverse(res.begin(),res.end());
        
        return res;
    }
};