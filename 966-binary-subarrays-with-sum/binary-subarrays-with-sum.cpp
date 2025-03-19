class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> u; // store no of times a prefixSum occurs
        u[0]=1;
        int prefixSum=0,cnt=0,k=goal;

        for(auto it:nums)
        {
            prefixSum+=it; // x=prefixSum
            int rem=prefixSum-k; // rem=x-k, check no of times rem occurs as a prefixSum in map

            if(u.find(rem)!=u.end())
            {
                cnt+=u[rem];
            }

            u[prefixSum]++;
        }
        return cnt;
    }
};