class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi<=0) return maxi; // when nums contains all -ve or -ve + 0 as it elements

        int n=nums.size(),sum=0;
        unordered_set<int> st(nums.begin(),nums.end());

        for(auto it:st)
        {
            if(it>0)
            sum+=it;
        }
        
        
        return sum;
    }
};