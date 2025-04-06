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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            int n=q.size(); // size of cur level OR no of elements in cur level

            vector<int> curLevel;
            for(int i=0;i<n;i++)
            {
                auto curNode=q.front();
                q.pop();

                curLevel.push_back(curNode->val);

                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }

            // now interation over elements of this level is complete, so add this level
            // to final ans
            res.push_back(curLevel);
        }

        return res;
    }
};