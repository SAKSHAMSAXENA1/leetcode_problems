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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur=root;

        while(cur!=NULL)
        {
            if(cur->left==NULL) // root's left does not exist
            {
                inorder.push_back(cur->val); // so visit root
                cur=cur->right; // now move to root's right
            }
            else
            {
                TreeNode* prev=cur->left;

                while(prev->right!=NULL && prev->right!=cur)
                {
                    prev=prev->right;
                }

                if(prev->right==NULL)
                {
                    prev->right=cur; // create temporary link
                    cur=cur->left;
                }
                else // temporary link already exists from prev->right to cur
                {
                    prev->right=NULL; // erase that temporary link
                    inorder.push_back(cur->val); // left subtree is visited, so visit root now
                    cur=cur->right; // root is visited, so move to root's right
                }
            }
        }

        return inorder;
    }
};