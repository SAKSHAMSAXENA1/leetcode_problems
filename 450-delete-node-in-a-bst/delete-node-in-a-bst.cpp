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
void insertNode(TreeNode* root,TreeNode* &key)
{
    TreeNode* cur=root;

    while(true)
    {
        if(root->val < key->val)
        {
            if(root->right)
            root=root->right; // search on right side
            else
            {
                root->right=key; // insert key as right child
                break;
            }
        }
        else // key->val < root->val
        {
            if(root->left)
            root=root->left; // search in left side
            else
            {
                root->left=key; // insert key as left child
                break;
            }
        }
    }
}
TreeNode* adjustChildren(TreeNode* root)
{
    if(root->right) // if right child of node to delete exists, it will replace deleted node
    {
        if(root->left)
        insertNode(root->right,root->left); // entire left subtree inserted inside right subtree

        return root->right;
    }

    // else left child will replace the deleted node
    return root->left;
}

bool findNodeToDelete(TreeNode* root,int &key)
{
    if(root==NULL) return false;

    if(root->left && root->left->val==key) // if left child is to be deleted
    {
        root->left=adjustChildren(root->left);
        return true;
    }

    if(root->right && root->right->val==key) // if right child is to be deleted
    {
        root->right=adjustChildren(root->right);
        return true;
    }

    if(key < root->val)
    {
        // search node to delete on left
        bool left=findNodeToDelete(root->left,key);
        if(left) return true;
    }
    // else
    // search node to delete on right
    bool right=findNodeToDelete(root->right,key);

    return right;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;

        if(root->val==key) // if root itself is to be deleted
        return adjustChildren(root);

        // else some non-root node is to be deleted
        findNodeToDelete(root,key);

        return root;
    }
};