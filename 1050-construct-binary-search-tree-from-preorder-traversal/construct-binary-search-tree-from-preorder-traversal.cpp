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
void insertNodeIntoBST(TreeNode* root,int &key)
{
    while(root)
    {
        if(key < root->val) // key must on left side of root
        {
            if(root->left) // search key on left side of root
                root=root->left;
            else
            {
                root->left=new TreeNode(key); // insert on left side of root
                break;
            }
        }
        else // root->val < key -> key must be on right side of root
        {
            if(root->right) // search key on right side of root
                root=root->right;
            else
            {
                root->right=new TreeNode(key); // insert key on right side of root
                break;
            }
        }
    }
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // each node is inserted as a leaf node into the already existing BST
        TreeNode* root=new TreeNode(preorder[0]);
        int n=preorder.size();

        for(int i=1;i<n;i++)
            insertNodeIntoBST(root,preorder[i]);

        return root;
    }
};