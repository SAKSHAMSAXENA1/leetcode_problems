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
int findMaxPathSum(TreeNode *root,int &maxSum)
{
    if(root==NULL) return 0;

    int leftSubtreeSum=findMaxPathSum(root->left,maxSum);
    leftSubtreeSum=max(0,leftSubtreeSum);
    int rightSubtreeSum=findMaxPathSum(root->right,maxSum);
    rightSubtreeSum=max(0,rightSubtreeSum);

    // max path sum ABOUT this node
    maxSum=max(maxSum,leftSubtreeSum+rightSubtreeSum+root->val);

    // return max path sum UPTIL this node
    return root->val+max(leftSubtreeSum,rightSubtreeSum);
}
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        findMaxPathSum(root,maxSum);
        return maxSum;
    }
};