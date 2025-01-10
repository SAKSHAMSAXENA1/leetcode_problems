struct Node{
    Node *links[26];
    vector<int> indices;
};

class Trie{
    public:
    Node *root;
    Trie()
    {
        root=new Node();
    }

    void insert(string &word, int &index)
    {
        Node *node=root;

        for(auto c: word)
        {
            if(node->links[c-'a']==NULL)
            {
                node->links[c-'a']=new Node();
            }
            node=node->links[c-'a'];
            node->indices.push_back(index);
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=products.size(),resSize=searchWord.size();
        sort(products.begin(),products.end());

        Trie ob;
        for(int i=0;i<n;i++)
        ob.insert(products[i],i);

        Node *node=ob.root;
        vector<vector<string>> res(resSize, vector<string>());

        for(int i=0;i<resSize;i++)
        {
            if(node->links[searchWord[i]-'a']==NULL)
            break;

            node=node->links[searchWord[i]-'a'];

            int noOfWords=min(3, (int)(node->indices).size());

            for(int j=0;j<noOfWords;j++)
            {
                res[i].push_back(products[node->indices[j]]);
            }
        }

        return res;
    }
};