#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        ll maxi=LLONG_MIN;
        unordered_map<int,ll> numToMinPreviousPrefixSum;
        vector<ll> prefixSum(n);
        prefixSum[0]=nums[0];
        numToMinPreviousPrefixSum[nums[0]]=0;

        for(int i=1;i<n;i++)
        prefixSum[i]=prefixSum[i-1]+nums[i];

        for(int j=1;j<n;j++)
        {
            int a=nums[j]+k,b=nums[j]-k;

            if(numToMinPreviousPrefixSum.find(a)!=numToMinPreviousPrefixSum.end())
            {
                maxi=max(maxi,prefixSum[j] - numToMinPreviousPrefixSum[a]);
            }

            if(numToMinPreviousPrefixSum.find(b)!=numToMinPreviousPrefixSum.end())
            {
                maxi=max(maxi,prefixSum[j] - numToMinPreviousPrefixSum[b]);
            }

            if(numToMinPreviousPrefixSum.find(nums[j])==numToMinPreviousPrefixSum.end())
            numToMinPreviousPrefixSum[nums[j]]=prefixSum[j-1];
            else
            numToMinPreviousPrefixSum[nums[j]]=
            min(numToMinPreviousPrefixSum[nums[j]],prefixSum[j-1]); // min(existing val,cur val)
        }

        if(maxi==LLONG_MIN) return 0;
        return maxi;
    }
};