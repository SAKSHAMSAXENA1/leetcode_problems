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

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left)
        root->left=removeLeafNodes(root->left,target);

        if(root->right)
        root->right=removeLeafNodes(root->right,target);
        
        if(isLeaf(root) && root->val==target) return NULL;

        return root;
    }
};