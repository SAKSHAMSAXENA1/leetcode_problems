struct Node{
    Node *links[26];
    bool endsWith=false;
};

class Trie{
    public:
    Node *root;

    Trie(){
        root=new Node();
    }

    void insert(string &word)
    {
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
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie ob;
        string res="";
        int n=sentence.size();

        for(auto it: dictionary)
        {
            ob.insert(it);
        }

        Node *node=ob.root;
        for(int i=0;i<n;i++)
        {
            /*if(sentence[i]==' ')
            {
                node=ob.root;
                continue;
            }*/
            //search
            if(sentence[i]==' ' || node->links[sentence[i]-'a']==NULL)
            {
                while(i<n && sentence[i]!=' ')
                {
                    res.push_back(sentence[i]);
                    i++;
                }

                if(i<n)
                res.push_back(' ');

                node=ob.root;
            }
            else
            {
                res.push_back(sentence[i]);

                node=node->links[sentence[i]-'a'];

                if(node->endsWith==true)
                {
                    while(i<n && sentence[i]!=' ')
                    i++;

                    if(i<n)
                    res.push_back(' ');

                    node=ob.root;
                }
            }
        }

        return res;
    }
};