class StockPrice {
public:
set<pair<int,int>> st; // {price,timestamp}
unordered_map<int,set<pair<int,int>>::iterator> timeToAddr; // {timeStamp,Addr of entry in st}
int latestTime,latestPrice;
    StockPrice() {
        latestTime=latestPrice=-1; 
    }
    
    void update(int timestamp, int price) {
        if(timeToAddr.find(timestamp)!=timeToAddr.end()) // prev entry exists for this timestamp
        {
            auto addrToDelete=timeToAddr[timestamp];
            st.erase(addrToDelete);
        }

        st.insert({price,timestamp});
        timeToAddr[timestamp]=st.find({price,timestamp});

        if(timestamp >= latestTime)
        {
            latestTime=timestamp;
            latestPrice=price;
        }
    }
    
    int current() {
        return latestPrice;
    }
    
    int maximum() {
        return st.rbegin()->first;
    }
    
    int minimum() {
        return st.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */