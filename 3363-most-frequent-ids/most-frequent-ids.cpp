#define ll long long
class SegmentTree{
    vector<ll> seg;
public:
    SegmentTree(int n)
    {
        seg.resize(4*n,0);
    }

    void update(int index,int low,int high,int &id,int &updateVal)
    {
        if(low==high) //  node interval converges to a single point= target 'id'
        {
            seg[index]+=updateVal;
            return;
        }

        // do binary search to find on which side the target id lies
        int mid=(low+high)/2;
        if(id<=mid) update(2*index+1,low,mid,id,updateVal);
        else update(2*index+2,mid+1,high,id,updateVal);

        // niche ka banda update hua hai toh upar ki nodes bhi change karo
        seg[index]=max(seg[2*index+1],seg[2*index+2]);
    }

    ll query()
    {
        return seg[0]; // most freq id in the node interval [0..n-1]
    }
};
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int maxi=*max_element(nums.begin(),nums.end()),n=nums.size();
        SegmentTree sgt(maxi+1);
        vector<ll> res;

        for(int i=0;i<n;i++)
        {
            sgt.update(0,0,maxi,nums[i],freq[i]);
            res.push_back(sgt.query());
        }

        return res;
    }
};