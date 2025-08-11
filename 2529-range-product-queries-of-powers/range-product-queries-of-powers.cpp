#define ll long long
#define mod (ll)(1e9+7)
class SegmentTree{
    vector<ll> seg;
public:
    void build(int index,int low,int high,vector<ll> &powers)
    {
        if(low==high)
        {
            seg[index]=powers[low];
            return;
        }

        int mid=(low+high)/2;
        build(2*index+1,low,mid,powers);
        build(2*index+2,mid+1,high,powers);

        seg[index]=(seg[2*index+1]*seg[2*index+2])%mod;
    }

    SegmentTree(int &n,vector<ll> &powers)
    {
        seg.resize(4*n);
        build(0,0,n-1,powers);
    }

    ll query(int index,int low,int high,int l,int r)
    {
        // no overlap: [l r][low high] or [low high][l r]
        if(r<low || high<l) return 1;

        // complete overlap: [l low high r]
        if(l<=low && high<=r) 
        return seg[index];

        // else partial overlap: no overlap(left)+complete overlap(right)
        //                   or: complete overlap(left)+no overlap(right)
        int mid=(low+high)/2;
        ll left=query(2*index+1,low,mid,l,r);
        ll right=query(2*index+2,mid+1,high,l,r);

        return (left*right)%(mod);
    }
};
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int bitsUsed=-1,t=n,largestPowerOf2=1,m=0;
        vector<int> res;
        vector<ll> powers;

        while(t)
        {
            bitsUsed++;
            t/=2;
        }

        largestPowerOf2=1<<bitsUsed;

        t=n;

        while(t)
        {
            if(t>=largestPowerOf2)
            {
                powers.push_back(largestPowerOf2);
                t-=largestPowerOf2;
                m++;
            }
            
            largestPowerOf2/=2;
        }

        reverse(powers.begin(),powers.end());

        SegmentTree sgt(m,powers);

        for(auto it:queries)
        {
            int l=it[0],r=it[1];
            ll ans=sgt.query(0,0,m-1,l,r);

            res.push_back(ans);
        }

        return res;
    }
};