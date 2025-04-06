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
int f(TreeNode* root,bool &res)
{
    if(root==NULL) return 0; // max height=0

    int lh=f(root->left,res);
    int rh=f(root->right,res);

    if(abs(lh-rh)>1) res=false;

    return 1+max(lh,rh);
}
    bool isBalanced(TreeNode* root) {
        bool res=true; // initially assume tree is height balanced
        f(root,res);
        return res;
    }
};