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
void preOrder(TreeNode *root,string ds,vector<string> &ans)
{
    if(root==NULL) return;

    if(ds.size()>0)
    ds=ds+"->";

    ds=ds+to_string(root->val);

    if(isLeaf(root))
    {
        ans.push_back(ds);
        return;
    }

    preOrder(root->left,ds,ans);
    preOrder(root->right,ds,ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        preOrder(root,"",ans);
        return ans;
    }
};