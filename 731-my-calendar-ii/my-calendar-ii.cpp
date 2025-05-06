class MyCalendarTwo {
public:
// lazy propagation
unordered_map<long,int> seg; // seg means noOfBookings 
unordered_map<long,int> lazy; // lazy means pendingBookings

int query(long index,int low,int high,int l,int r)
{
    // complete pending updates/bookings
    if(lazy[index]!=0)
    {
        seg[index]+=lazy[index]; // add penging bookings to existing bookings

        if(low!=high) // more than 1 nodes/ time slot in [low high]
        {
            lazy[2*index+1]+=lazy[index]; // lazy propagation of pendingBookings down
            lazy[2*index+2]+=lazy[index];
        }

        lazy[index]=0; // no pending bookings now
    }

    // no overlap
    if(high<l || r<low)
    return 0; //value which does not affect my noOfBookings in relevant interval(complete overlap)

    // complete overlap
    if(l<=low && high<=r)
    return seg[index];

    // else partial overlap=no overlap+complete overlap
    int mid=((long)low+high)/2;
    int left=query(2*index+1,low,mid,l,r);
    int right=query(2*index+2,mid+1,high,l,r);
    return max(left,right);
}

void update(long index,int low,int high,int l,int r)
{
    // complete pending updates/bookings
    if(lazy[index]!=0) // pendingBookings[index]!=0
    {
        seg[index]+=lazy[index]; // add pending bookings to existing bookings

        if(low!=high) // more than 1 node/time slots in node interavl [low high]
        {
            lazy[2*index+1]=lazy[index]; // lazy propagation of updates/pendingBookings down
            lazy[2*index+2]=lazy[index]; // to children
        }

        lazy[index]=0; // no pending bookings now for node interval [low high] 
    }

    // no overlap
    if(high<l || r<low)
    return;

    // complete overlap
    if(l<=low && high<=r)
    {
        seg[index]++; // noOfBookings[index]++;

        if(low!=high) // more than 1 nodes/ time slots in node interval [low high]
        {
            lazy[2*index+1]++; // pendingBookings[left child]++
            lazy[2*index+2]++; // pendingBookings[right child]++
        }

        return;
    }

    // else partial overlap
    int mid=((long)low+high)/2;
    update(2*index+1,low,mid,l,r); // left
    update(2*index+2,mid+1,high,l,r); // right

    // niche ka banda change hua hai, toh upar ki nodes ko bhi update karo
    seg[index]=max(seg[2*index+1],seg[2*index+2]);
}
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        int noOfBookings=query(0,0,1e9,startTime,endTime-1);
        if(noOfBookings==2)
        return false; // new booking cannot be made as already 2 bookings have been done

        update(0,0,1e9,startTime,endTime-1); // make new booking
        return true; // new booking successfully done
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */