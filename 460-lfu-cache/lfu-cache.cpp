class LFUCache {
public:
unordered_map<int,pair<list<pair<int,int>>::iterator,int>> u; // key->(address of dll node,value)
map<int,list<pair<int,int>>> freq; // counter->dll of nodes, where node=(key,cur_freq)
int n;
    LFUCache(int capacity) {
        n=capacity;
    }

    void makeMoreFrequentlyUsed(int key)
    {
        auto addressOfNode=u[key].first; // address of dll node corresponding to key

        auto &nodeToDelete=*(addressOfNode); // actual node to be deleted
        int f=nodeToDelete.second; // counter value of the node being deleted
        freq[f].erase(addressOfNode); // delete this node from dll of counter value=f

        // if no other element in dll for this counter value, delete this freq/counterval 
        // itself from map
        if(freq[f].empty()) 
        freq.erase(f);

        f++; // updated counter val for the node corres. to key
        freq[f].push_front({key,f}); // this node is now MRU node in dll of freq='f'

        u[key].first=freq[f].begin(); // store the new address of this node
    }
    
    int get(int key) {
        // if key doesn't exist in map
        if(u.find(key)==u.end()) return -1;

        // else key exists in map
        int val=u[key].second;

        makeMoreFrequentlyUsed(key);
        
        return val;
    }
    
    void put(int key, int value) {
        // if key already present in map
        if(u.find(key)!=u.end())
        {
            u[key].second=value; // update its value

            makeMoreFrequentlyUsed(key);

            return;
        }

        // else new node corres. to key is to be inserted

        if(n==0) // if space is not available
        {
            // delete LRU node of LFU dll

            int leastCounterVal=(*freq.begin()).first;
            auto &nodeToDelete=freq[leastCounterVal].back();

            int keyOfNodeToDelete=nodeToDelete.first;
            u.erase(keyOfNodeToDelete); // delete key of LRU node from map 'u'
            freq[leastCounterVal].pop_back(); // delete from dll corres. to leastCounterVal

            if(freq[leastCounterVal].empty())
            freq.erase(leastCounterVal);

            n++; // now space increases since a node is deleted
        }

        // it is the first time this key is being inserted, so its counter val=1

        freq[1].push_front({key,1}); //new node is MRU node of dll corres. to counter val=1
        u[key]={freq[1].begin(),value}; // store the addr of the new node, and value in map 'u'
        n--; // new node inserted, so available space decreases
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */