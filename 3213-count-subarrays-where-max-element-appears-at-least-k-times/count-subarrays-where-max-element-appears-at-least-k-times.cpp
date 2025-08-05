#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll res=0;
        int n=nums.size(),maxi=*max_element(nums.begin(),nums.end());
        int l=0,r=0,cntMaxi=0;

        while(r<n)
        {
            cntMaxi+=nums[r]==maxi; // acquire

            // while condn of the probm is true, update res
            while(cntMaxi==k)
            {
                res+=n-r;
                cntMaxi-=nums[l]==maxi; // release
                l++; // shrink the window (release)
            }

            // cntMaxi<k, i.e. condn of probm is not satisfied, so expand window
            r++; // expand the window (acquire)
        }

        return res;
    }
};