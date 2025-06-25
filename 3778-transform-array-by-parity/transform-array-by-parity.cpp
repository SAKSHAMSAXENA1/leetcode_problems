class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n=nums.size(),ones=0;
        vector<int> res(n,0);

        for(auto it:nums)
        ones+=it%2;

        int idx=n-1;
        while(ones)
        {
            res[idx]=1;
            idx--;
            ones--;
        }

        return res;
    }
};