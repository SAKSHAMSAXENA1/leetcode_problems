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
        if(root==p || root==q) return root;

        if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left,p,q); // search on left side

        else if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right,p,q); // search on right side

        // else one of the p & q is on the left, while the other is on the right of root
        // so root is the LCA of the two
        return root;
    }
};