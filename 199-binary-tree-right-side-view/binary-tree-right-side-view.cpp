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
        queue<TreeNode *> q;
        int curLevel=-1;
        q.push(root);

        // level order traversal
        while(!q.empty())
        {
            curLevel++;
            int n=q.size(),rightMostElement=INT_MAX;
            
            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                q.pop();

                rightMostElement=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            res.push_back(rightMostElement);
        }

        return res;
    }
};