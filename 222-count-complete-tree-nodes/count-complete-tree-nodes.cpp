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
int findLeftHeight(TreeNode* root)
{
    int height=0;
    while(root)
    {
        height++;
        root=root->left;
    }
    return height;
}
int findRightHeight(TreeNode* root)
{
    int height=0;
    while(root)
    {
        height++;
        root=root->right;
    }
    return height;
}
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0; // zero no of nodes in tree whose root==NULL

        int leftHeight=findLeftHeight(root);
        int rightHeight=findRightHeight(root);

        if(leftHeight==rightHeight) // perfect tree
        return (1<<leftHeight)-1; // so no of nodes = 2^h-1

        // else leftHeight != rightHeight, so not a perfect tree, so formula can't be used
        // therefore no of nodes=1 (root) + leftSubTree nodes+ rightSubTree nodes
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};