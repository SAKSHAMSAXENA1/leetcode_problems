/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void preOrder(TreeNode* root, unordered_map<int,TreeNode*> &parent,int &startValue,
int &destValue,TreeNode* &start,TreeNode* &dest,int &n)
{
    if(root->val==startValue) start=root; // root
    else if(root->val==destValue) dest=root;

    n++;

    if(root->left) // left
    {
        parent[root->left->val]=root;
        preOrder(root->left,parent,startValue,destValue,start,dest,n);
    }

    if(root->right) // right
    {
        parent[root->right->val]=root;
        preOrder(root->right,parent,startValue,destValue,start,dest,n);
    }
}

void dfs(TreeNode *root,unordered_map<int,TreeNode*> &parent,vector<bool> &vis,TreeNode* &dest,
string &ds,string &res)
{
    if(root==dest)
    {
        res=ds;
        return;
    }

    vis[root->val]=true;

    if(root->left && !vis[root->left->val])
    {
        ds.push_back('L');
        dfs(root->left,parent,vis,dest,ds,res);
        ds.pop_back();
    }

    if(root->right && !vis[root->right->val])
    {
        ds.push_back('R');
        dfs(root->right,parent,vis,dest,ds,res);
        ds.pop_back();
    }

    if(parent.find(root->val)!=parent.end() && !vis[parent[root->val]->val])
    {
        ds.push_back('U');
        dfs(parent[root->val],parent,vis,dest,ds,res);
        ds.pop_back();
    }
}

    string getDirections(TreeNode* root, int startValue, int destValue) {
        int n=0;
        TreeNode *start,*dest;
        unordered_map<int,TreeNode*> parent;
        preOrder(root,parent,startValue,destValue,start,dest,n);
        vector<bool> vis(n+1,false);
        string ds="",res="";

        dfs(start,parent,vis,dest,ds,res);
        
        return res;
    }
};