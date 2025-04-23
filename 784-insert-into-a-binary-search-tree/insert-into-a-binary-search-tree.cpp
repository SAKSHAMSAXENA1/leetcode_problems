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
void f(TreeNode* root,int &key)
{
    if(key < root->val)
    {
        if(root->left) 
        f(root->left,key); // search key on left side
        else
        {
            root->left=new TreeNode(key); // insert on left as leat node
            return;
        }
    }
    else // root->val < key
    {
        if(root->right)
        f(root->right,key); // search on right side
        else
        {
            root->right=new TreeNode(key); // insert on right as leaf node
            return;
        }
    }
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        
        f(root,val);
        return root;
    }
};