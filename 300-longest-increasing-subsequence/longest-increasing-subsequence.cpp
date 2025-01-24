class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),res=1,lisIndex=0;
        vector<int> dp(n,1),hash(n,0);

        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>res)
            {
                res=dp[i];
                lisIndex=i;
            }
            //res=max(res,dp[i]);
        }

        vector<int> temp;
        int index=lisIndex;

        while(hash[index]!=index)
        {
            temp.push_back(nums[index]);
            index=hash[index];
        }

        temp.push_back(nums[index]);
        reverse(temp.begin(),temp.end());

        for(auto it:temp)
        cout<<it<<" ";
        cout<<endl;

        return res;
    }
};