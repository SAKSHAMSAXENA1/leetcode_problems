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
// preorder: Rt L R <-> R L Rt (mirror img)
void mirrorImgOfPreorder(TreeNode* root, TreeNode* &prev)
{
    if(root==NULL) return;

    mirrorImgOfPreorder(root->right,prev); // right
    mirrorImgOfPreorder(root->left,prev); // left

    root->right=prev; // visit root
    root->left=NULL; // visit root

    prev=root;
}
    void flatten(TreeNode* root) {
        TreeNode* prev=NULL;
        mirrorImgOfPreorder(root,prev);
    }
};