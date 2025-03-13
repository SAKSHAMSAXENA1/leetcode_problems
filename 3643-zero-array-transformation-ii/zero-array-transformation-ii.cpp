class Solution {
public:
bool isSufficient(int &k,vector<int> &nums,vector<vector<int>> &queries)
{
    int n=nums.size(),sum=0; // sum is actually prefix sum
    vector<int> diff(n+1,0);
    // make suitable changes in diff, by processing each query -> O(Q)
    for(int i=0;i<k;i++)
    {
        int l=queries[i][0],r=queries[i][1],val=queries[i][2];
        diff[l]+=val;
        diff[r+1]-=val;
    }

    // prefix sum of diff array+checking if the queries taken were sufficent -> O(N)
    for(int i=0;i<n;i++)
    {
        sum+=diff[i];
        if(sum<nums[i]) return false;
    }

    return true;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0,r=queries.size(),ans=-1;
        // binary search to determine min no. of queries -> O(logQ)
        while(l<=r)
        {
            int mid=(l+r)>>1;

            if(isSufficient(mid,nums,queries)) // O(Q+N)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans; // ans=-1 indicates all queries combined are also insufficient
    }
};