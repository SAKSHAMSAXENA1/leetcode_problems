class LockingTree {
public:
vector<int> lockedBy;
vector<int> parent;
vector<vector<int>> adj;
void buildAdj(vector<vector<int>> &adj,vector<int> &lockedBy,int &n)
{
    for(int i=0;i<n;i++)
    {
        if(parent[i]!=-1) // !root node
        {
            adj[parent[i]].push_back(i);
        }
    }
}

bool hasLockedDescendant(int node,vector<vector<int>> &adj,vector<int> &lockedBy)
{
    if(lockedBy[node]!=-1) // node is locked
    return true;

    for(auto descendant: adj[node])
    {
        if(hasLockedDescendant(descendant,adj,lockedBy)) return true;
    }

    return false;
}

bool hasLockedAncestor(int node,vector<int> &parent,vector<int> &lockedBy)
{
    if(node==-1) return false;

    if(lockedBy[node]!=-1) return true;

    if(hasLockedAncestor(parent[node],parent,lockedBy)) return true;

    return false;
}

void unlockAll(int node,vector<vector<int>> &adj,vector<int> &lockedBy)
{
    lockedBy[node]=-1; // unlock the cur node

    for(auto descendant: adj[node])
    unlockAll(descendant,adj,lockedBy); // unlock all the descendants
}


    LockingTree(vector<int>& parent) {
        int n=parent.size();
        lockedBy.resize(n,-1); // -1 : not locked by any user
        this->parent=parent;
        adj.resize(n,vector<int>());
        buildAdj(adj,parent,n);
    }
    
    bool lock(int num, int user) {
        if(lockedBy[num]==-1) // node is currently unlocked
        {
            lockedBy[num]=user;
            return true;
        } 

        return false;
    }
    
    bool unlock(int num, int user) {
        if(lockedBy[num]==user) // node is currently locked by 'user'
        {
            lockedBy[num]=-1; // node is now unlocked
            return true;
        }

        return false;
    }
    
    bool upgrade(int num, int user) {
        if(lockedBy[num]!=-1) // num is locked
        return false;

        if(!hasLockedDescendant(num,adj,lockedBy)) // doesn't have any locked descendant
        return false;

        if(hasLockedAncestor(parent[num],parent,lockedBy)) // has a locked ancestor
        return false;

        unlockAll(num,adj,lockedBy); // unlock all descendants of 'num'
        lockedBy[num]=user; // num is now locked by 'user'
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */