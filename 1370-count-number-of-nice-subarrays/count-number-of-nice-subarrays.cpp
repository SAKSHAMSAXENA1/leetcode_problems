class Solution {
public:
    int f(vector<int> &nums,int k)
    {
        // cnt of subarrays where no of odd numbers<=k
        if(k<0) return 0;

        int l=0,r=0,n=nums.size(),cnt=0,oddCnt=0;

        while(r<n)
        {
            oddCnt+=nums[r]%2; // (acquire)

            while(oddCnt>k) // while desired condn->(oddCnt<=k) is false
            {
                oddCnt-=nums[l]%2; // (release)
                l++; // shrink the window (release)
            }

            // now oddCnt<=k, so update the cnt of such valid subarrays
            cnt+=r-l+1;
            r++; // expand the window (acquire)
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};