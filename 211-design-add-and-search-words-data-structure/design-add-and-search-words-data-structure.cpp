struct Node {
    Node *links[26];
    bool endsWith=false;
};
class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *node=root;

        for(auto c: word)
        {
            if(node->links[c-'a']==NULL)
            {
                node->links[c-'a']=new Node();
            }
            node=node->links[c-'a'];
        }
        node->endsWith=true;
    }

    bool f(string word, int index, Node *root)
    {
        int n=word.size();
        if(index==n)
        {
            return root->endsWith;
            /*if(root && root->endsWith) return true;
            return false;*/
        }
        
        bool res=false;
        Node *node=root;
        for(int i=index;i<n;i++)
        {
            if(word[i]=='.')
            {
                for(char j='a';j<='z';j++)
                {
                    if(node->links[j-'a']!=NULL)
                    res=res| f(word,i+1,node->links[j-'a']);
                }

                return res;
            }
            else if(node->links[word[i]-'a']==NULL) return false;
            else
            {
                node=node->links[word[i]-'a'];
            }
        }

        return node->endsWith;
    }
    
    bool search(string word) {
        return f(word,0,this->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */