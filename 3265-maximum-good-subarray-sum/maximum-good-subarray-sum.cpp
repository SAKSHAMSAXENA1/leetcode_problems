#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        ll maxi=LLONG_MIN;
        unordered_map<int,ll> mp;
        vector<ll> prefixSum(n);
        prefixSum[0]=nums[0];
        mp[nums[0]]=0;

        for(int j=1;j<n;j++)
        {
            prefixSum[j]=prefixSum[j-1]+nums[j];
            int a=nums[j]+k,b=nums[j]-k;

            if(mp.find(a)!=mp.end())
            {
                maxi=max(maxi,prefixSum[j] - mp[a]);
            }

            if(mp.find(b)!=mp.end())
            {
                maxi=max(maxi,prefixSum[j] - mp[b]);
            }

            if(mp.find(nums[j])==mp.end())
            mp[nums[j]]=prefixSum[j-1];
            else
            mp[nums[j]]=
            min(mp[nums[j]],prefixSum[j-1]); // min(existing val,cur val)
        }

        if(maxi==LLONG_MIN) return 0;
        return maxi;
    }
};