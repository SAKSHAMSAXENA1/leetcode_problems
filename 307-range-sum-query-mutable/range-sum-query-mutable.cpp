class NumArray {
public:
vector<int> seg,arr;
int n;

void build(int index,int low,int high)
{
    if(low==high) // interval of node represents a single value
    {
        seg[index]=arr[low];
        return;
    }

    int mid=(low+high)/2;
    build(2*index+1,low,mid); // left
    build(2*index+2,mid+1,high); // right;
    seg[index]=seg[2*index+1]+seg[2*index+2];
}

void updateSGTree(int index,int low,int high,int i,int &val)
{
    if(low==high) // interval/range of node represents a single element (target:i, here)
    {
        seg[index]=arr[i]=val;
        return;
    }

    // do binary search to find on which side index 'i' lies
    int mid=(low+high)/2;
    if(i<=mid)
    updateSGTree(2*index+1,low,mid,i,val); // 'i' lies on left side
    else 
    updateSGTree(2*index+2,mid+1,high,i,val); // 'i' lies on right side

    // niche ka banda change hua hai, toh upar vali nodes ko bhi update kardo
    seg[index]=seg[2*index+1]+seg[2*index+2];
}

int query(int index,int low,int high,int &l,int &r)
{
    // no overlap-> [low high][l r] OR [l r][low high]
    if(high<l || r<low) // node's interval outside query range [l r]
    return 0; // since this interval is not part of our query range [l r]

    // complete overlap-> [l low high r]
    if(l<=low && high<=r) // node's interval lies completely inside query range [l r]
    return seg[index]; // since this node's interval lies completely inside our query range [l r]
    
    // else partial overlap=no overlap(left)+complete overlap(right) 
    // OR complete overlap(left) + no overlap(right)
    int mid=(low+high)/2;
    int left=query(2*index+1,low,mid,l,r);
    int right=query(2*index+2,mid+1,high,l,r);
    return left+right; // so include both left and right
}
    NumArray(vector<int>& nums) {
        arr=vector<int>(nums.begin(),nums.end());
        n=nums.size();
        seg.resize(4*n,0);
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        updateSGTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */