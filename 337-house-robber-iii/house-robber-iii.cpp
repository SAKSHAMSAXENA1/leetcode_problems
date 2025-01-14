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
 
 #define tn TreeNode
class Solution {
public:
    int f(tn *root, unordered_map<tn*,int> &dp)
    {
        if(!root) return 0;

        if(dp.find(root)!=dp.end()) return dp[root];

        int temp=0;

        if(root->left) temp+=f(root->left->left,dp)+f(root->left->right,dp);

        if(root->right) temp+=f(root->right->left,dp)+f(root->right->right,dp); 

        int take=root->val+temp;

        int notTake=f(root->left,dp)+f(root->right,dp);

        return dp[root]=max(take, notTake);
    }
    int rob(TreeNode* root) {
        unordered_map<tn*,int> dp;
        return f(root,dp);
    }
};