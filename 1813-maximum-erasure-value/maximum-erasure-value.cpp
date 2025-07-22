class Solution {
public:
bool hasDuplicates(unordered_map<int,int> &u)
{
    for(auto it:u)
    {
        if(it.second>1) return true;
    }

    return false;
}
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=0,l=0,r=0,n=nums.size(),sum=0;
        unordered_map<int,int> u;

        while(r<n)
        {
            u[nums[r]]++; // acquire
            sum+=nums[r]; // acquire

            while(hasDuplicates(u)==true) // while condn of probm is false, shrink the window
            {
                u[nums[l]]--; // release
                if(u[nums[l]]==0) u.erase(nums[l]); // release
                sum-=nums[l]; // release
                l++; // shrink the window (release)
            }

            // now the condn of probm: window must have unique elements is true
            // so update the result
            maxi=max(maxi,sum);

            r++; // expand the window (acquire)
        }

        return maxi;
    }
};