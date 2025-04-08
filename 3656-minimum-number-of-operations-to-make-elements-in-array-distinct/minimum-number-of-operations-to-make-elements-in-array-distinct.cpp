class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(),i=0;
        unordered_map<int,int> u;
        for(auto it:nums)
        u[it]++;

        if(u.size()==n) return 0;
        int cnt=1;

        while(true)
        {
            int k=0;
            while(i<n && k<3 && u.size()!=n-i)
            {
                u[nums[i]]--;
                if(u[nums[i]]==0) u.erase(nums[i]);
                i++;
                k++;
            }

            if(u.size()==n-i) break; // return cnt;
            cnt++;
        }

        return cnt;
    }
};