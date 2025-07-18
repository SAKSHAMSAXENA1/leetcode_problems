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
#define ull unsigned long long
class Solution {
public:
ull findSum(TreeNode* root)
{
    if(!root) return 0;

    return findSum(root->left)+findSum(root->right)+root->val;
}

ull f(TreeNode* root,ull &maxi,ull &completeTreeSum)
{
    if(!root) return 0;

    ull leftSum=0,rightSum=0;
    if(root->left)
    {
        leftSum=f(root->left,maxi,completeTreeSum);
        maxi=max(maxi,(completeTreeSum-leftSum)*leftSum);
    }

    if(root->right)
    {
        rightSum=f(root->right,maxi,completeTreeSum);
        maxi=max(maxi,(completeTreeSum-rightSum)*rightSum);  
    }

    return leftSum+rightSum+root->val;
}
    int maxProduct(TreeNode* root) {
        ull maxi=0,completeTreeSum=findSum(root);

        f(root,maxi,completeTreeSum);

        return maxi%((ull)1e9+7);
    }
};