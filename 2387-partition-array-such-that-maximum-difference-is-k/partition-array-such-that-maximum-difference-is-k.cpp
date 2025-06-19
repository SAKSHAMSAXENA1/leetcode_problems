class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int partitions=0,maxi=INT_MIN,mini=INT_MAX;

        for(auto it:nums)
        {
            maxi=max(maxi,it);
            mini=min(mini,it);

            if(maxi-mini<=k) continue;

            // else maxi-mini>k
            partitions++;
            maxi=mini=it;
        }

        return partitions+1;
    }
};