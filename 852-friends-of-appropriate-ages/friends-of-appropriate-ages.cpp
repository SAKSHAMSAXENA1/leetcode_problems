class SegmentTree{ 
    vector<int> seg;
public:
    void build(int index,int low,int high)
    {
        if(low==high) // node interval converges to a single node
        {
            seg[index]=1;
            return;
        }

        int mid=(low+high)/2;
        build(2*index+1,low,mid); // left
        build(2*index+2,mid+1,high); // right
        seg[index]=seg[2*index+1]+seg[2*index+2]; // left+right
    }

    SegmentTree(int &n)
    {
        seg.resize(4*n);
        build(0,0,n-1);
    }

    int query(int index,int low,int high,int &l,int &r,vector<int> &nums)
    {
        // no overlap = node interval lies completely outside query range
        // [l r][low high] or [low high][l r]
        if(r<nums[low] || nums[high]<l)
        return 0;

        // complete overlap = node interval lies completely inside query range
        // [l low high r]
        if(l<=nums[low] && nums[high]<=r)
        return seg[index]; 

        // else partial overlap=no overlap(left)+complete overlap(right)
        //                   or=complete overlap(left)+no overlap(right)
        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,l,r,nums);
        int right=query(2*index+2,mid+1,high,l,r,nums);
        return left+right; 
    }
};

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size(),res=0;
        sort(ages.begin(),ages.end());
        SegmentTree sgt(n);

        for(auto it:ages)
        {
            int l=it/2+7+1;
            if(l<=it) 
            res+=sgt.query(0,0,n-1,l,it,ages)-1; // r=it
        }

        return res; 
    }
};