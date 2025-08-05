class SegmentTree{
    vector<int> seg;

public:
    void build(int index,int low,int high,vector<int> &arr)
    {
        if(low==high) // node interval converges to a single point
        {
            seg[index]=arr[low];
            return;
        }

        int mid=(low+high)/2;
        build(2*index+1,low,mid,arr); // left
        build(2*index+2,mid+1,high,arr); // right

        seg[index]=max(seg[2*index+1],seg[2*index+2]); // max(left,right)
    }

    SegmentTree(int &n,vector<int> &arr)
    {
        seg.resize(4*n);
        build(0,0,n-1,arr);
    }

    bool query(int &fruitVal)
    {
        return fruitVal <= seg[0]; // if the fruit can be placed anywhere in the range [0 .. n-1]
    }

    void update(int index,int low,int high,int &fruitVal) // place leftMost
    {
        if(low==high) // node interval converges to a single node
        {
            seg[index]=INT_MIN; // a very small value which prevents baskets[low] from being used
            // again
            return;
        }

        // else do binary search to place the fruit with value 'fruitVal' in either of the left 
        // and right halves, prefering the left side over right side (leftmost)

        int mid=(low+high)/2;

        if(fruitVal <= seg[2*index+1]) // fruit can be placed on left side
        update(2*index+1,low,mid,fruitVal); // left
        else // fruit has to be placed on right side only
        update(2*index+2,mid+1,high,fruitVal); // right

        // niche ka banda change hua hai, upar ki nodes bhi update karo 
        seg[index]=max(seg[2*index+1],seg[2*index+2]); // max(left,right)
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size(),fruitsPlaced=0;
        SegmentTree sgt(n,baskets);

        for(auto it:fruits)
        {
            if(sgt.query(it)==true) // if the fruit can be placed anywhere in the range [0..n-1]
            {
                fruitsPlaced++;
                sgt.update(0,0,n-1,it);
            }
        }

        return n-fruitsPlaced;
    }
};