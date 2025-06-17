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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,int> childrenSum;
        int curLevelSum=0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n=q.size();
            int nextLevelSum=0;

            while(n--)
            {
                auto node=q.front();
                q.pop();

                if(node==root)
                node->val=0;
                else
                node->val=curLevelSum-childrenSum[parent[node]];

                if(node->left)
                {
                    parent[node->left]=node;
                    childrenSum[node]+=node->left->val;
                    nextLevelSum+=node->left->val;
                    q.push(node->left);
                }

                if(node->right)
                {
                    parent[node->right]=node;
                    childrenSum[node]+=node->right->val;
                    nextLevelSum+=node->right->val;
                    q.push(node->right);
                }
            }

            curLevelSum=nextLevelSum;
        }

        return root;
    }
};