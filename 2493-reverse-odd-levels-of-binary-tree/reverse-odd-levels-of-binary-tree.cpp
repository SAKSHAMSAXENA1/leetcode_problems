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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int curLevel=0;

        while(!q.empty())
        {
            int n=q.size();
            vector<int> values;
            vector<TreeNode*> nodes;

            for(int i=0;i<n;i++)
            {
                auto node=q.front();
                q.pop();

                if(curLevel%2) // odd level
                {
                    values.push_back(node->val);
                    nodes.push_back(node);
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(curLevel%2) // odd level
            {
                for(int i=0;i<n;i++)
                {
                    nodes[i]->val=values[n-1-i];
                }
            }

            curLevel++;
        }

        return root;
    }
};