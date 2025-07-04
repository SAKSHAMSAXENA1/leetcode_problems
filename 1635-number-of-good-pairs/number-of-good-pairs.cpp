class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            cnt+=(nums[i]==nums[j]);
        }
        return cnt;
    }
};