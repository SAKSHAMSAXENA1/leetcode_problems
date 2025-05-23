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
int height(TreeNode *node,int &maxDiameter)
{
    if(node==NULL) return 0;

    int lh=height(node->left,maxDiameter);
    int rh=height(node->right,maxDiameter);

    maxDiameter=max(maxDiameter,lh+rh);

    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter=0;
        height(root,maxDiameter);
        return maxDiameter;
    }
};