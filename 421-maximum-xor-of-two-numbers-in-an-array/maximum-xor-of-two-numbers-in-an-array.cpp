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

            if(node->links[bit]==NULL)
            {
                node->links[bit]=new Node();
            }
            node=node->links[bit];
        }
    }

    int maxXorWithTrie(int &num)
    {
        Node *node=root;
        int res=0;

        for(int i=31;i>=0;i--)
        {
            int desiredBit=!((num>>i)&1);

            if(node->links[desiredBit])
            {
                res=res|(1<<i);
                node=node->links[desiredBit];
            }
            else
            {
                node=node->links[!desiredBit];
            }
        }

        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie ob;
        for(auto it:nums)
        ob.insert(it);

        int maxi=0;
        for(auto it:nums)
        maxi=max(maxi,ob.maxXorWithTrie(it));

        return maxi;
    }
};