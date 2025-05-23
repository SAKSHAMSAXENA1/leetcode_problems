#define ll long long
class SGTree{
vector<ll> seg;
public:
    ll query(int index,int low,int high,int l,int r)
    {
        // no overlap: [low high][l r] or [l r][low high]
        if(high<l || r<low)
        return 0;

        // complete overlap: [l low high r]
        if(l<=low && high<=r)
        return seg[index];

        // else partial overlap: no overlap(left) + complete overlap(right)
        //                   or: complete overlap(left) + no overlap(right)
        int mid=(low+high)/2;
        ll left=query(2*index+1,low,mid,l,r); 
        ll right=query(2*index+2,mid+1,high,l,r);

        return left+right;
    }

    void update(int index,int low,int high,int &idx) // point update
    {
        if(low==high) // node interval represents a single node (target: idx)
        {
            seg[index]=1; // mark nums2[idx] as visited
            return;
        }

        // else do binary search to fing in which half idx lies
        int mid=(low+high)/2;
        if(idx<=mid)
        update(2*index+1,low,mid,idx); // left
        else
        update(2*index+2,mid+1,high,idx); // right

        // niche ka banda update hua hai toh upar ki nodes bhi update karo
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }

    SGTree(int &n)
    {
        seg.resize(4*n,0);
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        SGTree sgt(n);
        unordered_map<int,int> indexInNums2;

        for(int i=0;i<n;i++)
        indexInNums2[nums2[i]]=i;

        ll res=0;

        for(int i=0;i<n;i++)
        {
            int idx=indexInNums2[nums1[i]];
            ll leftCommonCount=sgt.query(0,0,n-1,0,idx);
            ll leftCount=i;
            ll leftNotCommonCount=leftCount-leftCommonCount;
            ll elementsAfterIdxNums2=n-1-idx;
            ll rightCommonCount=elementsAfterIdxNums2-leftNotCommonCount;

            res+=leftCommonCount*rightCommonCount;
            sgt.update(0,0,n-1,idx); // mark nums2[idx] (nums1[i]) as visited
        }

        return res;
    }
};