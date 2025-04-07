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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode *> q;
        q.push(root);
        int level=-1;

        while(!q.empty())
        {
            level++;
            int n=q.size();
            vector<int> curLevel(n);

            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                q.pop();

                if(level%2) // odd level->reverse order
                curLevel[n-1-i]=node->val;
                else // even level->normal order
                curLevel[i]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            res.push_back(curLevel);
        }

        return res;
    }
};