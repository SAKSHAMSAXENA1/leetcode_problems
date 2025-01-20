struct Node {
    //vector<vector<Node *>> links(26, vector<Node*> (26,NULL));
    //Node *links[26][26];
    unordered_map<int, Node*> links; 
    int endsWith=0;
};

class Trie{
    public:
    Node *root;

    Trie()
    {
        root=new Node();
    }

    void insert(string &w, long long &cnt)
    {
        Node *node=root;

        int i=0,n=w.size(),j;

        for(int i=0,j=n-1-i;i<n;i++,j--)
        {
            int hash=(w[i]-'a'+1)*255+(w[j]-'a'+1);
            if(node->links.find(hash)==node->links.end())
            {
                node->links[hash]=new Node();
            }
            node=node->links[hash];

            if(node->endsWith) cnt+=node->endsWith;
        }

        node->endsWith++;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        Trie ob;
        long long cnt=0;

        for(auto w: words)
        ob.insert(w,cnt);

        return cnt;
    }
};