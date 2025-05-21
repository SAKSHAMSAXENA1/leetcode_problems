class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),prev=0;
        vector<int> diffArray(n+1,0);

        for(auto it:queries)
        {
            diffArray[it[0]]--;
            diffArray[it[1]+1]++;
        }

        for(int i=0;i<n;i++)
        {
            diffArray[i]+=prev;

            if(nums[i]+diffArray[i]>0) return false;
            prev=diffArray[i];
        }

        return true;
    }
};