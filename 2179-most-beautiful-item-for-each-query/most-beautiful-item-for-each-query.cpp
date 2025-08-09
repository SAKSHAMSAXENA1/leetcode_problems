class Solution {
public:
int upperBound(vector<vector<int>> &nums,int &n,int &key)
{
    int l=0,h=n-1,res=n;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(key < nums[mid][0])
        {
            res=mid; // one possible ans is index 'mid'
            h=mid-1; // reduce h in order to find first element which is > key
        }
        else l=mid+1;
    }

    return res;
}
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        vector<int> res,prefixMax(n);

        sort(items.begin(),items.end());

        prefixMax[0]=items[0][1];

        for(int i=1;i<n;i++)
        prefixMax[i]=max(prefixMax[i-1],items[i][1]);

        for(auto it:queries)
        {
            int ub=upperBound(items,n,it);
            int queryRes=0;

            if(ub!=0) // cost of atleast 1 item is lesser than equal to it
            {
                int idx=ub-1;
                queryRes=prefixMax[idx];
            }

            res.push_back(queryRes);
        }

        return res;
    }
};