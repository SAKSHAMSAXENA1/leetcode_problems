class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> u; // store cnt of each prefixSum in map
        int cnt=0,prefixSum=0;
        u[0]=1; // kind of necessary step

        for(auto it:nums)
        {
            prefixSum+=it; // x
            int rem=prefixSum-k; // rem=x-k, search no of times rem occurs in map

            if(u.find(rem)!=u.end())
            {
                cnt+=u[rem];
            }

            u[prefixSum]++;
        }

        return cnt;
    }
};