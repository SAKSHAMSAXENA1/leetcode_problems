class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());

        int n = nums.size(),cntMaxi = 0;

        if(n != maxi + 1) return false;

        for(int i=0;i<n;i++)
        {
            int idx = abs(nums[i]) - 1;

            if(nums[idx] > 0)
            {
                nums[idx] *= -1;

                if(abs(nums[i]) == maxi)
                cntMaxi++;
            } 
            else if(abs(nums[i]) !=  maxi) return false;
            else cntMaxi++;
        }

        return cntMaxi == 2;
    }
};