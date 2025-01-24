class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),lastIndex=0,maxi=1;
        vector<int> dp(n,1),hash(n,0);

        for(int i=0;i<n;i++)
        {
            hash[i]=i;

            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && dp[prev]+1>dp[i])
                {
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }

            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastIndex=i;
            }
        }

        vector<int> temp;
        int index=lastIndex;
        while(hash[index]!=index)
        {
            temp.push_back(nums[index]);
            index=hash[index];
        }

        temp.push_back(nums[index]);
        reverse(temp.begin(),temp.end());
        return temp;
    }
};