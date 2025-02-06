class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> u;
        int res=0,n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                u[nums[i]*nums[j]]++;
            }
        }

        for(auto it:u)
        {
            res+=(it.second)*(it.second-1)*8/2;
        }

        return res;
    }
};