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

    void insert(string &s, int &maxLength, int &totStrings)
    {
        Node *node=root;
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if(node->links[s[i]-'a']==NULL)
            {
                node->links[s[i]-'a']=new Node();
            }

            node=node->links[s[i]-'a'];
            node->cntPrefix++;
            if(node->cntPrefix==totStrings)
            maxLength=i+1;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie ob;

        int totStrings=strs.size(),maxLength=0;

        for(int i=0;i<totStrings-1;i++)
        ob.insert(strs[i],maxLength,totStrings);

        ob.insert(strs[totStrings-1],maxLength,totStrings);

        if(maxLength) return strs[0].substr(0, maxLength);
        return "";
    }
};