class MyCalendar {
public:
// lazy propagation
unordered_map<long,bool> seg; // seg represents 'isBooked'
unordered_map<long,bool> lazy; // lazy represents 'hasPendingUpdate'
    
bool query(long index,int low,int high,int l,int r)
{
    // complete any pending updates
    if(lazy[index]==true) // hasPendingUpdates[index]==true
    {
        seg[index]=true; // isBooked[index]=true;

        if(low!=high) // node interval has more than 1 node (time slot)
        {
            lazy[2*index+1]=lazy[2*index+2]=true; // lazy propagation of updates
        }

        lazy[index]=false; // no pending updates now
    }

    // no overlap->[low high][l r] or [l r][low high]
    if(high<l || r<low)
    return false; //value which does not affect isBooked status of relevant(overlapping) interval

    // complete overlap->[l low high r]
    // node interval lies completely inside query range
    if(l<=low && high<=r)
    return seg[index]; // isBooked[index]

    // else partial overlap= no overlap(left)+complete overlap(right)
    //               or    = complete overlap(right)+no overlap(left)
    int mid=((long)(low)+high)/2;
    bool left=query(2*index+1,low,mid,l,r);
    bool right=query(2*index+2,mid+1,high,l,r);
    return left | right; // if any of left or right is booked, whole of low to high presented
    // as booked
}

void update(long index,int low, int high,int l,int r)
{
    // complete any pending updates
    if(lazy[index]==true) // there are pending updates
    {
        seg[index]=true;

        if(low!=high) // more than 1 nodes (time slots) in the interval [low high]
        {
            lazy[2*index+1]=lazy[2*index+2]=true; // lazy propagation of update to children
        }

        lazy[index]=false; // no pending updates now
    }

    // no overlap->[low high][l r] or [l r][low high]
    if(high<l || r<low) return;

    // complete overlap->[l low high r]
    // node's interval [low high] lies completely inside query range [l r]
    if(l<=low && high<=r)
    {
        seg[index]=true;

        if(low!=high) // more than 1 nodes (time slots) in node interval [low high]
        {
            lazy[2*index+1]=lazy[2*index+2]=true; // lazy propagation of updates to children
        }

        return;
    }

    // else partial overlap=no overlap(left)+complete overlap(right)
    //                  or =complete overlap(left)+no overlap(right)
    int mid=((long)low+high)/2;
    update(2*index+1,low,mid,l,r); // left
    update(2*index+2,mid+1,high,l,r); // right
    // niche ka banda change hua hai, toh upar ki nodes bhi update karo
    seg[index]=seg[2*index+1] | seg[2*index+2];
}

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        bool isBooked=query(0,0,1e9,startTime,endTime-1);

        if(isBooked==true) 
        return false; // new booking cannot be made

        update(0,0,1e9,startTime,endTime-1);
        return true; // new booking done successfully
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */