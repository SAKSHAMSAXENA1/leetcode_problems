class Solution {
public:
int f(vector<int> &nums,int k)
{
    // no of subarrays having <=k odd elements (CONDN OF THE PROBLEM)
    int l=0,r=0,n=nums.size(),cntOdd=0,res=0;

    while(r<n)
    {
        cntOdd+=nums[r]%2; // (acquire)

        while(cntOdd>k) // while condn of the problem is not satisfied, shrink
        {
            cntOdd-=nums[l]%2; // (release)
            l++; // shrink the window (release)
        }

        // now the window/subarray has <=k odd elements, i.e.
        // now the condn of the problem is satisfied, so update the result
        res+=r-l+1;
        r++; // expand the window (acquire)
    }

    return res;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};