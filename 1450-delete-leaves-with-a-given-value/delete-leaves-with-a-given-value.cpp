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
bool isLeaf(TreeNode *root)
{
    return root->left==NULL && root->right==NULL;
}

void postOrder(TreeNode *root,int &target)
{
    if(root->left)
    postOrder(root->left, target); // left

    if(root->right)
    postOrder(root->right,target); // right

    // root
    if(root->left && isLeaf(root->left) && root->left->val==target)
    root->left=NULL;

    if(root->right && isLeaf(root->right) && root->right->val==target)
    root->right=NULL;

}
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        postOrder(root,target);
        if(isLeaf(root) && root->val==target) root=NULL;

        return root;
    }
};