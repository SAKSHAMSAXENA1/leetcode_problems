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
ull findSum(TreeNode* root,unordered_map<TreeNode*,ull> &u)
{
    if(!root) return 0;

    return u[root]=findSum(root->left,u)+findSum(root->right,u)+root->val;
}

void f(TreeNode* root,unordered_map<TreeNode*,ull> &u,ull &maxi,ull &completeTreeSum)
{
    if(root->left)
    {
        maxi=max(maxi,(completeTreeSum-u[root->left])*u[root->left]);
        f(root->left,u,maxi,completeTreeSum);
    }

    if(root->right)
    {
        maxi=max(maxi,(completeTreeSum-u[root->right])*u[root->right]);
        f(root->right,u,maxi,completeTreeSum);
    }
}
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*,ull> u;
        findSum(root,u);
        ull maxi=0,completeTreeSum=u[root];

        f(root,u,maxi,completeTreeSum);

        return maxi%((ull)1e9+7);
    }
};