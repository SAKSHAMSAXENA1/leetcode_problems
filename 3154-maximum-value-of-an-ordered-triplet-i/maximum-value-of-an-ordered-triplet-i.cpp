#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                maxi=max(maxi,((ll)nums[i]-nums[j])*nums[k]);
            }
        }
        return maxi;
    }
};