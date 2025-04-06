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
    int maxDepth(TreeNode* root) {
        int res=0;
        if(root==NULL) return res;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            res++;
            int n=q.size(); // size of cur level OR no of elements in cur level

            for(int i=0;i<n;i++)
            {
                auto curNode=q.front();
                q.pop();

                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
        }

        return res;
    }
};