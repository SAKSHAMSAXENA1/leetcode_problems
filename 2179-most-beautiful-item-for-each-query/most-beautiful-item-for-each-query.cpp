class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        vector<int> res,prices,prefixMax(n);
        vector<pair<int,int>> sortedItems;
        for(auto it:items)
        {
            prices.push_back(it[0]);
            sortedItems.push_back({it[0],it[1]});
        }

        sort(prices.begin(),prices.end());
        sort(sortedItems.begin(),sortedItems.end());

        prefixMax[0]=sortedItems[0].second;

        for(int i=1;i<n;i++)
        prefixMax[i]=max(prefixMax[i-1],sortedItems[i].second);

        for(auto it:queries)
        {
            auto ub=upper_bound(prices.begin(),prices.end(),it);
            int queryRes=0;

            if(ub!=prices.begin()) // cost of atleast 1 item is lesser than equal to it
            {
                int idx=ub-prices.begin()-1;
                queryRes=prefixMax[idx];
            }

            res.push_back(queryRes);
        }

        return res;
    }
};