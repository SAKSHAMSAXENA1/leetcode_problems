class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(),i=0;
        unordered_map<int,int> u;
        for(auto it:nums)
        u[it]++;

        if(u.size()==n) return 0;

        for(int i=0;i<n;i++)
        {
            u[nums[i]]--;
            if(u[nums[i]]==0) u.erase(nums[i]);

            if(u.size()==n-i-1) return i/3+1;
        }

        return -1;
    }
};