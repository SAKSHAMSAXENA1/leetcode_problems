class SegmentTree{
public:
    vector<int> seg;

    void build(int index,int low,int high,vector<vector<int>> &nums)
    {
        if(low==high) // node interval converges to a range
        {
            seg[index]=nums[low][1];
            return;
        }

        int mid=(low+high)/2;
        build(2*index+1,low,mid,nums);
        build(2*index+2,mid+1,high,nums);

        seg[index]=max(seg[2*index+1],seg[2*index+2]);
    }

    SegmentTree(int &n,vector<vector<int>> &nums)
    {
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }

    int query(int index,int low,int high,int r)
    {
        // no overlap: node interval lies outside query range
        // [0 r][low high]
        if(r < low)
        return INT_MIN; // very small val which prevents elements of this interval from inclusion

        // complete overlap: node interval lies completely inside query range
        // [0 low high r]
        if(0<=low && high<=r)
        return seg[index];

        // else partial overlap:no overlap(left)+complete overlap(right)
        //                   or:complete overlap(left)+no overlap(right)
        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,r);
        int right=query(2*index+2,mid+1,high,r);

        return max(left,right);
    }

};
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        vector<int> res,prices;
        for(auto it:items)
        {
            prices.push_back(it[0]);
        }

        sort(prices.begin(),prices.end());
        sort(items.begin(),items.end());

        SegmentTree sgt(n,items);

        for(auto it:queries)
        {
            auto ub=upper_bound(prices.begin(),prices.end(),it);
            int queryRes=0;

            if(ub!=prices.begin()) // cost of atleast 1 item is lesser than equal to it
            {
                int idx=ub-prices.begin()-1;
                queryRes=sgt.query(0,0,n-1,idx);
            }

            res.push_back(queryRes);
        }

        return res;
    }
};