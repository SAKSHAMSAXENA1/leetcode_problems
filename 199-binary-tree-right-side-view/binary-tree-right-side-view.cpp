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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;

        map<int,int> u;
        queue<pair<TreeNode *,int>> q; // (node,level)
        q.push({root,0});

        // level order traversal
        while(!q.empty())
        {
            auto node=q.front().first;
            int level=q.front().second;
            q.pop();

            // overwrite any previous values of u[level] with the rightmost value
            u[level]=node->val;
            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }

        for(auto it:u)
        {
            res.push_back(it.second);
        }

        return res;
    }
};