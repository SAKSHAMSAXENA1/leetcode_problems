class Solution {
public:
    int f(vector<int> &nums,int k)
    {
        // no of subarrays where no of unique elements<=k
        if(k<=0) return 0; // no such non-empty subarray possible where no of unique elements<=0

        int l=0,r=0,n=nums.size(),cnt=0;
        unordered_map<int,int> uniqueElements;

        while(r<n)
        {
            uniqueElements[nums[r]]++; // (acquire)

            while(uniqueElements.size()>k)
            {
                uniqueElements[nums[l]]--; // (release)
                if(uniqueElements[nums[l]]==0) 
                uniqueElements.erase(nums[l]);  // (release)
                l++; // shrink the window (release)
            }

            // now no of unique elements in window/subarray<=k, so update the cnt
            cnt+=r-l+1;
            r++; // expand the window (acquire)
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};