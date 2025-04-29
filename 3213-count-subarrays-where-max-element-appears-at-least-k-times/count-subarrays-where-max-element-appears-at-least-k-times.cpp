#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll res=0;
        int l=0,r=0,n=nums.size(),maxElement=*max_element(nums.begin(),nums.end()),freq=0;

        while(r<n)
        {
            freq+=(nums[r]==maxElement); // (acquire)

            while(freq==k) // while condn of probm->(freq of maxElement==k) is satisfied
            {
                res+=n-r; // update result

                // keep shrinking to find the core subarray, where freq of maxElement==k
                freq-=(nums[l]==maxElement); // (release)
                l++; // shrink the window (release)
            }

            // now condn of the probm->(freq of maxElement==k) is false, so expand
            r++; // expand the window (acquire)
        }

        return res;
    }
};