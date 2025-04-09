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
map<int,int> u; // (level,node)
void preOrder(TreeNode *root,int level)
{
    if(root==NULL) return;

    u[level]=root->val; // overwrite any prev values of u[level]

    preOrder(root->left,level+1);
    preOrder(root->right,level+1);
    // right subtree is visited after left subtree which ensures that the rightmost values
    // always overwrite the previous values of u for their level

}
    vector<int> rightSideView(TreeNode* root) {
        preOrder(root,0);
        vector<int> res;
        for(auto it:u)
        res.push_back(it.second);
        return res;
    }
};