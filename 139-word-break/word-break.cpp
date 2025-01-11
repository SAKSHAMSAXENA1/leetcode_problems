struct Node{
    Node *links[26];
    bool endsWith=false;
};

class Trie{
    public:
    Node *root;
    Trie()
    {
        root=new Node();
    }

    void insert(string &s)
    {
        Node *node=root;

        for(auto c:s)
        {
            if(node->links[c-'a']==NULL)
            {
                node->links[c-'a']=new Node();
            }
            node=node->links[c-'a'];
        }
        node->endsWith=true;
    }
};

class Solution {
public:
    bool f(int index, string &s, Node *root, Node *absoluteRoot, vector<unordered_map<Node *,bool>> &dp)
    {
        int n=s.size();
        if(index==n)
        {
            return root->endsWith;
            /*if(!root || root->endsWith==false) return false;
            return true;*/

            /*if(root && root->endsWith==true) return true;
            return false;*/
        }

        if(dp[index].find(root)!=dp[index].end()) return dp[index][root];
        Node *node=absoluteRoot;
        bool res=false;

        for(int i=index;i<n;i++)
        {
            if(node->links[s[i]-'a']!=NULL)
            {
                node=node->links[s[i]-'a'];
                if(node->endsWith==true) 
                res=res|(f(i+1,s,node,absoluteRoot,dp));
            }
            else break;   
        }

        return dp[index][root]=res;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie ob;

        for(auto it: wordDict)
        ob.insert(it);

        int n=s.size();
        vector<unordered_map<Node *,bool>> dp(n+1);

        return f(0,s,ob.root,ob.root,dp);
    }
};