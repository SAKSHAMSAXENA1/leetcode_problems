class LUPrefix {
public:
vector<int> seg;
int streamSize;
void update(int index,int low,int high,int i)
{
    if(low==high) // target 't' is found
    {
        seg[index]=1;
        return;
    }

    // binary search to find 'i' lies on which side ->left or right
    int mid=(low+high)/2;
    if(i<=mid) update(2*index+1,low,mid,i); // 'i' lies on left
    else update(2*index+2,mid+1,high,i); // 'i' lies right

    seg[index]=seg[2*index+1]; // value of left half
    if(seg[2*index+1]==mid-low+1) // prefix is complete
    seg[index]+=seg[2*index+2]; // so we can now add any suffix (if present)
}

    LUPrefix(int n) {
        streamSize=n;
        seg.resize(4*n,0);
    }
    
    void upload(int video) {
        update(0,0,streamSize-1,video-1); // video-1 : to convert into 0-based indexing
    }
    
    int longest() {
        return seg[0];
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */