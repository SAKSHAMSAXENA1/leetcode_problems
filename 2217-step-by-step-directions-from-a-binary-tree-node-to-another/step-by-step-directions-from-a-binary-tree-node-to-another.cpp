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
void dfs(TreeNode *root,int &n)
{
    n++;

    if(root->left) dfs(root->left,n);

    if(root->right) dfs(root->right,n);
}

void preOrder(TreeNode* root, vector<TreeNode*> &parent,int &startValue,int &destValue,
TreeNode* &start,TreeNode* &dest)
{
    if(root->val==startValue) start=root; // root
    else if(root->val==destValue) dest=root;

    if(root->left) // left
    {
        parent[root->left->val]=root;
        preOrder(root->left,parent,startValue,destValue,start,dest);
    }

    if(root->right) // right
    {
        parent[root->right->val]=root;
        preOrder(root->right,parent,startValue,destValue,start,dest);
    }
}

bool findPath(TreeNode *root,vector<TreeNode*> &parent,vector<bool> &vis,TreeNode* &dest,
string &ds,string &res)
{
    if(root==dest)
    {
        res=ds;
        return true;
    }

    vis[root->val]=true;

    if(root->left && !vis[root->left->val])
    {
        ds.push_back('L');
        if(findPath(root->left,parent,vis,dest,ds,res)) return true;
        ds.pop_back();
    }

    if(root->right && !vis[root->right->val])
    {
        ds.push_back('R');
        if(findPath(root->right,parent,vis,dest,ds,res)) return true;
        ds.pop_back();
    }

    if(parent[root->val]!=NULL && !vis[parent[root->val]->val])
    {
        ds.push_back('U');
        if(findPath(parent[root->val],parent,vis,dest,ds,res)) return true;
        ds.pop_back();
    }

    return false;
}

    string getDirections(TreeNode* root, int startValue, int destValue) {
        int n=0;
        dfs(root,n);
        vector<TreeNode*> parent(n+1,NULL);
        TreeNode *start,*dest;
        preOrder(root,parent,startValue,destValue,start,dest);
        vector<bool> vis(n+1,false);
        string ds="",res="";

        findPath(start,parent,vis,dest,ds,res);
        
        return res;
    }
};