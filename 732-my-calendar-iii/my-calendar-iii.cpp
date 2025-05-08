class MyCalendarThree {
public:
unordered_map<long,int> seg,lazy;

void update(long index,int low,int high,int l,int r)
{
    if(lazy[index]!=0)
    {
        seg[index]+=lazy[index];

        if(low!=high)
        {
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }

    if(high<l || r<low)
    return;

    if(l<=low && high<=r)
    {
        seg[index]++;

        if(low!=high)
        {
            lazy[2*index+1]++;
            lazy[2*index+2]++;
        }
        return;
    }

    int mid=((long)low+high)/2;
    update(2*index+1,low,mid,l,r);
    update(2*index+2,mid+1,high,l,r);
    seg[index]=max(seg[2*index+1],seg[2*index+2]);
}

int query(long index,int low,int high,int l,int r)
{
    if(lazy[index]!=0)
    {
        seg[index]+=lazy[index];

        if(low!=high)
        {
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }

        lazy[index]=0;
    }

    if(high<l || r<low)
    return 0;

    if(l<=low && high<=r)
    return seg[index];

    int mid=((long long)low+high)/2;
    int left=query(2*index+1,low,mid,l,r);
    int right=query(2*index+2,mid+1,high,l,r);
    return max(left,right);
}
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        update(0,0,1e9,startTime,endTime-1);
        return seg[0];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */