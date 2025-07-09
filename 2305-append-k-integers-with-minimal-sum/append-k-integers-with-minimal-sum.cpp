#define ll long long
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ll sum=0;

        int mini=min(k,nums[0]-1);
        sum+=(ll)mini*(mini+1)/2;
        k-=mini;

        for(int i=0;i<n-1 && k>0;i++)
        {
            if(nums[i]==nums[i+1]) continue;
            int elementsInBetween=nums[i+1]-nums[i]-1;
            int mini=min(elementsInBetween,k);
            sum+=(ll)(nums[i]+mini)*(nums[i]+mini+1)/2-(ll)(nums[i])*(nums[i]+1)/2;
            k-=mini;
        }

        sum+=(ll)(nums[n-1]+k)*(nums[n-1]+k+1)/2-(ll)(nums[n-1])*(nums[n-1]+1)/2;
        return sum;
    }
};