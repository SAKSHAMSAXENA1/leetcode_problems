class Router {
public:
int m;
set<pair<int,pair<int,int>>> pkts; // {source,{destination,timestamp}}
unordered_map<int,deque<int>> destToTimestamps; // dest : <timestamps>
queue<pair<int,pair<int,int>>> q; // {source,{destination,timestamp}}
    Router(int memoryLimit) {
        m=memoryLimit;
    }

    void removeOldestPacket()
    {
        auto pktToRemove=q.front();
        q.pop();
        pkts.erase(pktToRemove);
        int toRemoveDest=pktToRemove.second.first;
        destToTimestamps[toRemoveDest].pop_front();
        if(destToTimestamps[toRemoveDest].size()==0) 
        destToTimestamps.erase(toRemoveDest);
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(pkts.find({source,{destination,timestamp}})!=pkts.end()) // packet already exists
        return false;

        q.push({source,{destination,timestamp}}); // add new pkt
        pkts.insert({source,{destination,timestamp}});
        destToTimestamps[destination].push_back(timestamp);

        if(q.size()>m)
        {
            removeOldestPacket();
        }

        return true; 
    }
    
    vector<int> forwardPacket() {
        if(!q.size()) return {};

        auto oldestPkt=q.front();
        removeOldestPacket();
        return {oldestPkt.first,oldestPkt.second.first,oldestPkt.second.second};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(destToTimestamps.find(destination)==destToTimestamps.end()) 
        return 0; // no pkts inside q corresponding to this destination

        auto left=lower_bound(destToTimestamps[destination].begin(),
        destToTimestamps[destination].end(),startTime);
        auto right=upper_bound(destToTimestamps[destination].begin(),
        destToTimestamps[destination].end(),endTime);
        return (right-left);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */