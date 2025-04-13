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

#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,ll>> q; //(node,index)
        q.push({root,0});
        ll res=0;

        while(!q.empty())
        {
            int n=q.size(),referenceIndex=q.front().second;
            ll firstVal=q.front().second,lastVal=q.back().second;
            res=max(res,lastVal-firstVal+1);

            for(int i=0;i<n;i++)
            {
                auto node=q.front().first;
                ll absoluteIndex=q.front().second;
                q.pop();
                ll relativeIndex=absoluteIndex-referenceIndex;

                if(node->left) q.push({node->left,2*relativeIndex+1});
                if(node->right) q.push({node->right,2*relativeIndex+2});
            }
        }

        return res;
    }
};