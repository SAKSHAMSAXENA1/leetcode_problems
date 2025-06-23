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
void preorder(TreeNode* root,int maxi,int &cnt)
{
    cnt+=(maxi <= (root->val));

    maxi=max(maxi,root->val);

    if(root->left)
    preorder(root->left,maxi,cnt);

    if(root->right)
    preorder(root->right,maxi,cnt);
}
    int goodNodes(TreeNode* root) {
        int cnt=0;
        preorder(root,INT_MIN,cnt);
        return cnt;
    }
};