class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachableIndex=0,n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(maxReachableIndex<i) // index 'i' is out of my reach
            return false;

            // else i<=maxReachableIndex => index 'i' is within my reach
            // so update maxReachableIndex
            maxReachableIndex=max(maxReachableIndex,i+nums[i]);
        }

        // all indices including 'n-1' were within my reach, so return true
        return true;
    }
};