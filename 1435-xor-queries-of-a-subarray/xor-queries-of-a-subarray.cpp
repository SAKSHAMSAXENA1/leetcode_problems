class SGTree{
    vector<int> seg;
    public:
    void build(int index,int low,int high,vector<int> &arr)
    {
        if(low==high)
        {
            seg[index]=arr[low];
            return;
        }

        int mid=(low+high)/2;
        build(2*index+1,low,mid,arr); // left
        build(2*index+2,mid+1,high,arr); // right
        seg[index]=seg[2*index+1] ^ seg[2*index+2];
    }

    int query(int index,int low,int high,int l,int r)
    {
        // no overlap
        if(high<l || r<low) return 0;

        // complete overlap
        if(l<=low && high<=r) return seg[index];

        // else partial overlap=no overlap(left)+complete overlap(right) or vice-versa
        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,l,r);
        int right=query(2*index+2,mid+1,high,l,r);
        return left ^ right;
    }

    SGTree(vector<int> &arr)
    {
        int n=arr.size();
        seg.resize(4*n);
        build(0,0,n-1,arr);
    }
};
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        SGTree sgt(arr);
        int n=arr.size();
        vector<int> res;

        for(auto query:queries)
        {
            int l=query[0],r=query[1];
            res.push_back(sgt.query(0,0,n-1,l,r));
        }

        return res;
    }
};