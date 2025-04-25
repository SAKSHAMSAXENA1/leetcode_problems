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
unordered_map<TreeNode* ,int> dpMinVal,dpMaxVal;
int minVal(TreeNode* root)
{
    if(root==NULL) return INT_MAX;

    if(dpMinVal.find(root)!=dpMinVal.end()) return dpMinVal[root];

    return dpMinVal[root]=min(root->val,min(minVal(root->left),minVal(root->right)));
}

int maxVal(TreeNode* root)
{
    if(root==NULL) return INT_MIN;

    if(dpMaxVal.find(root)!=dpMaxVal.end()) return dpMaxVal[root];

    return dpMaxVal[root]=max(root->val,max(maxVal(root->left),maxVal(root->right)));
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;

        bool leftSmaller=(root->left) ? maxVal(root->left) < root->val : true;
        bool rightBigger=(root->right) ? root->val < minVal(root->right) : true;

        return leftSmaller && rightBigger && isValidBST(root->left) && isValidBST(root->right);
    }
};