#define ll long long
#define mod (ll)(1e9+7)
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size(),k=n-1;
        ll res=0;
        vector<int> diff(n+1,0);
        priority_queue<int> pq;
        sort(nums.begin(),nums.end());

        for(auto it:requests)
        {
            diff[it[0]]++;
            diff[it[1]+1]--;
        }

        for(int i=0;i<n;i++)
        {
            if(i>0) diff[i]+=diff[i-1];

            if(diff[i]>0) pq.push(diff[i]);
        }

        while(!pq.empty())
        {
            res=(res+((ll)pq.top() * nums[k])%mod)%mod;
            pq.pop();
            k--;
        }

        return res;
    }
};