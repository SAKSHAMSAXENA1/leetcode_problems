#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll res=0,sum=0;
        int l=0,r=0,n=nums.size();

        while(r<n)
        {
            sum+=nums[r]; // (acquire)

            while(sum*(r-l+1)>=k) // while cond->(score<k) is false/not satisfied
            {
                sum-=nums[l]; // (release)
                l++; // shrink the window (release)
            }

            // now condn->(score<k) is true/satisfied, so update the result
            res+=r-l+1;
            r++; // expand the window (acquire)
        }

        return res;
    }
};