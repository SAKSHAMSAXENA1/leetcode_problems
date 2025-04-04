class LRUCache {
public:
list<int> dll; // doubly linked list
unordered_map<int,pair<list<int>::iterator,int>> u; // key->(addr,val)
int n; // remaining space
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void makeRecentlyUsed(int key)
    {   
        dll.erase(u[key].first); // erase the node from dll
        dll.push_front(key); // insert new node corr. to key at front of dll to make it MRU
        u[key].first=dll.begin(); // store the addr of new node corr. to key in map
    }

    int get(int key) {
        if(u.find(key)==u.end()) // key not found
        return -1;

        makeRecentlyUsed(key);

        return u[key].second;
    }
    
    void put(int key, int value) {
        if(u.find(key)!=u.end()) // key already exists
        {
            u[key].second=value; // update its value in map
            makeRecentlyUsed(key);
        }
        else
        {
            if(n==0) // no space available
            {
                u.erase(dll.back()); // erase LRU from map
                dll.pop_back(); // erase LRU from back of dll, since LRU is at back of dll
                n++; // make space for new node/(key,val)
            }

            dll.push_front(key); // insert new node corresponding to key in dll
            u[key]={dll.begin(),value}; // insert addr and val of new node corr. to key
            n--; // reduce available space
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */