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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);

        TreeNode* copyOfRoot=root;
        while(true)
        {
            if(val < root->val)
            {
                if(root->left)
                root=root->left; // search on left side
                else 
                {
                    root->left=new TreeNode(val); // insert on left as leaf node
                    break;
                }
            }
            else // root->val < val
            {
                if(root->right)
                root=root->right; // search on right side
                else
                {
                    root->right=new TreeNode(val); // insert on right as leaf node
                    break;
                }
            }
        }

        return copyOfRoot;
    }
};