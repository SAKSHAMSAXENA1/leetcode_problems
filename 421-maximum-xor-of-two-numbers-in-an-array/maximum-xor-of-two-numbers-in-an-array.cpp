struct Node{
    Node *links[2];
};

class Trie{
    public:
    Node *root;

    Trie(){
        root=new Node();
    }

    void insert(int &num)
    {
        Node *node=root;

        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->links[bit]==NULL){
                node->links[bit]=new Node();
            }
            node=node->links[bit];
        }
    }

    int maxXorOfTrieWithNum(int &x){
        int res=0;
        Node *node=root;

        for(int i=31;i>=0;i--)
        {
            int desiredBit=!((x>>i)&1);

            if(node->links[desiredBit]==NULL)
            {
                node=node->links[!desiredBit];
            }
            else
            {
                res=res|(1<<i);
                node=node->links[desiredBit];
            }
            
        }

        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
    Trie *obj=new Trie();
    int maxi=0;
    for(auto it:nums)
    obj->insert(it);

    for(auto x:nums)
    maxi=max(maxi,obj->maxXorOfTrieWithNum(x));

    return maxi;
    }
};