class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),i,cnt=0;
        vector<int> diff(n+1,0);

        for(i=0;i+k-1<n;i++)
        {
            if(i>0) diff[i]+=diff[i-1];

            bool flipCurrentBit=diff[i]%2;

            if(flipCurrentBit) nums[i]=!nums[i];

            if(nums[i]==0)
            {
                cnt++;
                diff[i]++;
                diff[i+k]--;
            }
        }

        for(;i<n;i++)
        {
            if(i>0) diff[i]+=diff[i-1];

            bool flipCurrentBit=diff[i]%2;

            if(flipCurrentBit) nums[i]=!nums[i];

            if(nums[i]==0) return -1; 
        }

        return cnt;
    }
};