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
void inorder(TreeNode* root,int &sum)
{
    if(root==NULL) return;
    inorder(root->left,sum);
    sum+=root->val;
    inorder(root->right,sum);
}

void update(TreeNode* root,int &sum)
{
    if(root==NULL) return;
    update(root->left,sum);
    int cur=root->val;
    root->val=sum;
    sum-=cur;
    update(root->right,sum);
}
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        inorder(root,sum);
        update(root,sum);
        return root;
    }
};