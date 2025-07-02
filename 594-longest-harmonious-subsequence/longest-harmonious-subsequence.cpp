class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        int res=0;

        for(auto it:nums)
        {
            freq[it]++;
        }

        for(auto it:freq)
        {
            if(freq.find(it.first+1)!=freq.end())
            res=max(res,freq[it.first]+freq[it.first+1]);
        }

        return res;
    }
};