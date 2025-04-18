/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

void createStringStream(string &data,queue<string> &streamQ)
{
    string word="";
    int n=data.size();

    for(int i=0;i<n;i++)
    {
        if(data[i]==',')
        {
            streamQ.push(word);
            word="";
        }
        else word.push_back(data[i]);
    }
}

string nextVal(queue<string> &streamQ) // alternative to getLine() of string stream
{
    string val=streamQ.front();
    streamQ.pop();
    return val;
}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        string res="";
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            if(node==NULL)
            {
                res.append("#,");
            }
            else
            {
                res.append(to_string(node->val)+',');
                q.push(node->left);
                q.push(node->right);
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        queue<string> streamQ; // alternative to string stream
        createStringStream(data,streamQ);

        queue<TreeNode*> q; // for level order traversal 

        TreeNode* root=new TreeNode(stoi(nextVal(streamQ))); // whenever you create a non-NULL
        q.push(root); // node, push it into the q

        while(!q.empty())
        {
            auto node=q.front(); // this is the node, whose children are to be attached
            q.pop();

            string temp=nextVal(streamQ);
            if(temp=="#")
                node->left=NULL;
            else 
            {
                node->left=new TreeNode(stoi(temp)); // whenever you create a non-NULL node
                q.push(node->left); // push it into the q
            }

            temp=nextVal(streamQ);
            if(temp=="#")
                node->right=NULL;
            else
            {
                node->right=new TreeNode(stoi(temp)); // whenever you create a non-NULL node
                q.push(node->right); // push it into the q
            } 
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));