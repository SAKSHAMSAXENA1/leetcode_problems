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
map<int,vector<pair<int,int>>> u;
void preOrder(TreeNode *root,int row,int col)
{
    if(!root) return;

    u[col].push_back({row,root->val});
    preOrder(root->left,row+1,col-1);
    preOrder(root->right,row+1,col+1);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        preOrder(root,0,0);

        for(auto el:u)
        {
            res.push_back({});
            sort(el.second.begin(),el.second.end());
            for(auto node: el.second)
            res.back().push_back(node.second);
        }

        return res;
    }
};