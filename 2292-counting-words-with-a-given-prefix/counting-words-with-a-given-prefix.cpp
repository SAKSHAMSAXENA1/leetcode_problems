struct Node{
    Node *links[26];
    int cntPrefix=0;
};

class Trie{
    public:
    Node *root;
    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node *node=root;

        for(auto it: word)
        {
            if(node->links[it-'a']==NULL)
            {
                node->links[it-'a']=new Node();
            }
            node=node->links[it-'a'];
            node->cntPrefix++;
        }
    }

    int cntOfPrefixes(string &pref)
    {
        Node *node=root;

        for(auto it:pref)
        {
            if(node->links[it-'a']==NULL)
            {
                return 0;
            }
            else node=node->links[it-'a'];
        }

        return node->cntPrefix;
    }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie obj;

        for(auto it: words)
        obj.insert(it);

        return obj.cntOfPrefixes(pref);
    }
};