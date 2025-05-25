class SGTree{
    vector<int> seg; // RMIQ
public:
    void build(int index,int low,int high,vector<int> &baskets)
    {
        if(low==high) // node interval represents a single element
        {
            seg[index]=low;
            return;
        }

        int mid=(low+high)/2;
        build(2*index+1,low,mid,baskets); // left
        build(2*index+2,mid+1,high,baskets); // right

        seg[index]=(baskets[seg[2*index+1]]>=baskets[seg[2*index+2]]) ? 
        seg[2*index+1] : seg[2*index+2];
    }

    int query(int index,int low,int high,int &fruit,vector<int> &baskets)
    {
        if(seg[index]==-1) // all baskets of range [low high] already filled
        return -1; // invalid index which prevents elements of [low high] from inclusion

        if(baskets[seg[index]]<fruit) // no basket of range [low high] is big enough
        return -1; // invalid index which prevents elements of [low high] from inclusion

        // else baskets[seg[index]] >= fruit : some basket of range [low high] is big enough
        // so fruit can be placed in some basket of range [low high]

        if(low==high) // node interval [low high] represents single vacant big enough basket
        return low; // fruit placed in basket at index 'low'

        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,fruit,baskets); 

        if(left!=-1) // fruit is placed in some basket on left
        return left; // RMIQ

        // else try to place fruit in some basket on right
        int right=query(2*index+2,mid+1,high,fruit,baskets);
        return right; // RMIQ
    }

    void update(int index,int low,int high,int &i,vector<int> &baskets)
    {
        if(low==high) // low==high==i => target index 'i' is reached
        {
            seg[index]=-1; // now this basket is filled and no other fruit can be placed in it
            return;
        }

        // else do binary search to find on which side target index 'i' lies
        int mid=(low+high)/2;
        if(i<=mid)
        update(2*index+1,low,mid,i,baskets); // 'i' lies on left half/side
        else
        update(2*index+2,mid+1,high,i,baskets); // 'i' lies on right half/side

        // niche ka banda update hua hai toh upar ki nodes bhi update karo

        if(seg[2*index+1]==-1) // left half completely filled
        seg[index]=seg[2*index+2];
        else if(seg[2*index+2]==-1) // right half completely filled
        seg[index]=seg[2*index+1];
        else // if(seg[2*index+1]!=-1 && seg[2*index+2]!=-1)
        // both left and right halves have some vacant baskets
        seg[index]=(baskets[seg[2*index+1]]>=baskets[seg[2*index+2]]) ?
                    seg[2*index+1] : seg[2*index+2];
    }

    SGTree(vector<int> &baskets)
    {
        int n=baskets.size();
        seg.resize(4*n);
        build(0,0,n-1,baskets);
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SGTree sgt(baskets);
        int cntFruitsPlaced=0,n=baskets.size();

        for(auto fruit:fruits)
        {
            int idxOfBasketToFill=sgt.query(0,0,n-1,fruit,baskets);

            if(idxOfBasketToFill==-1) // no vacant basket is big enough
            continue;

            sgt.update(0,0,n-1,idxOfBasketToFill,baskets);
            cntFruitsPlaced++;
        }

        return n-cntFruitsPlaced;
    }
};