class Solution {
public:
int upperBound(vector<pair<int,int>> &nums,int &n,int &key)
{
    int l=0,h=n-1,res=n;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(key < nums[mid].first)
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
        vector<pair<int,int>> sortedItems;
        for(auto it:items)
        {
            sortedItems.push_back({it[0],it[1]});
        }

        sort(sortedItems.begin(),sortedItems.end());

        prefixMax[0]=sortedItems[0].second;

        for(int i=1;i<n;i++)
        prefixMax[i]=max(prefixMax[i-1],sortedItems[i].second);

        for(auto it:queries)
        {
            int ub=upperBound(sortedItems,n,it);
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