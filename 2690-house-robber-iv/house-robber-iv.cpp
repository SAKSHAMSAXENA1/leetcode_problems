class Solution {
public:
bool isSufficient(vector<int> &nums,int &capability,int &k,int &n)
{
    int housesRobbed=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]<=capability)
        {
            housesRobbed++; // rob this house
            i++; // skip the adjacent house
        }
    }

    return k<=housesRobbed;
}
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end()),r=*max_element(nums.begin(),nums.end());
        int ans=r,n=nums.size();

        while(l<=r)
        {
            int mid=(l+r)>>1; // mid represents the current capability
            if(isSufficient(nums,mid,k,n)) // if current capability is big enough to rob atleast
            // k houses
            {
                ans=mid;
                r=mid-1; // minimize the capability
            }
            else // current capability is insufficient
            l=mid+1; // increase the capability
        }

        return ans;
    }
};