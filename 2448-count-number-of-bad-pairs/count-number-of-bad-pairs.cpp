#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll n=nums.size(),totPairs=n*(n-1)/2,goodPairs=0;
        unordered_map<int,int> freq;

        for(int i=0;i<n;i++)
        {
            int curVal=i-nums[i];
            goodPairs+=freq[curVal];
            freq[curVal]++;
        }

        return totPairs-goodPairs;
    }
};