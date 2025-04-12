/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) 
        return root;

        TreeNode *leftVal=lowestCommonAncestor(root->left,p,q);
        TreeNode *rightVal=lowestCommonAncestor(root->right,p,q);

        if(leftVal!=NULL && rightVal!=NULL) return root;

        // else return whichever is not NULL
        if(leftVal!=NULL) return leftVal;

        // now only rightVal is not NULL so return rightVal
        return rightVal;
    }
};