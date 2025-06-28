class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;
        vector<int> res;
        int n=nums.size();

        for(int i=0;i<n;i++)
        temp.push_back({nums[i],i});

        auto comp=[&](pair<int,int> &a,pair<int,int> &b)
        {
            if(a.first==b.first) return a.second<b.second; // val same, shorter index first
            return a.first>b.first; // greater val first
        };

        sort(temp.begin(),temp.end(),comp);

        for(int i=0;i<k;i++)
        res.push_back(temp[i].second);

        sort(res.begin(),res.end());

        for(auto &it:res)
        it=nums[it];

        return res;
    }
};