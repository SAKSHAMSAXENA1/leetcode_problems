/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nulptr), right(nulptr) {}
 *     TreeNode(int x) : val(x), left(nulptr), right(nulptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#define l long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,l>> q; //(node,index)
        q.push({root,0});
        l res=0;

        while(!q.empty())
        {
            int n=q.size(),referenceIndex=q.front().second;
            l firstVal=q.front().second,lastVal=q.back().second;
            res=max(res,lastVal-firstVal+1);

            for(int i=0;i<n;i++)
            {
                auto node=q.front().first;
                l absoluteIndex=q.front().second;
                q.pop();
                l relativeIndex=absoluteIndex-referenceIndex;

                if(node->left) q.push({node->left,2*relativeIndex+1});
                if(node->right) q.push({node->right,2*relativeIndex+2});
            }
        }

        return res;
    }
};