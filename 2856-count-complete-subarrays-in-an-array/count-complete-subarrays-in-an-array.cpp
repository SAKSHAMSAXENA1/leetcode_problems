class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> u;
        for(auto it:nums) u[it]++;
        int res=0,n=nums.size(),uniqueElements=u.size(),l=0,r=0;
        u.clear();

        while(r<n)
        {
            u[nums[r]]++; // (acquire)

            while(u.size()==uniqueElements) // while subarray/window is complete
            {
                res+=n-r; // update res
                u[nums[l]]--; // (release)
                if(u[nums[l]]==0) u.erase(nums[l]); // (release)
                l++; // shrink the window (release)
            }

            // now the subarray/window is not complete, so expand the window/subarray
            r++; // expand the window (acquire)
        }

        return res;
    }
};