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
TreeNode *first=NULL,*middle=NULL,*last=NULL,*prev=NULL;
void traverse(TreeNode* root)
{
    if(root==NULL) return;

    traverse(root->left); // left

    if(prev!=NULL) // root, do business
    {
        if(prev->val >= root->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else last=root;
        }
    }

    prev=root;

    traverse(root->right); // right
}
    void recoverTree(TreeNode* root) {
        traverse(root);
        if(last!=NULL) // swapped nodes are not adjacent
        swap(first->val,last->val);
        else // swapped nodes are adjacent, as last==NULL
        swap(first->val,middle->val);
    }
};