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
void traverse(TreeNode* root,vector<int> &inorder)
{
    if(root==NULL) return;

    traverse(root->left,inorder); // left

    inorder.push_back(root->val); // root, do business

    traverse(root->right,inorder); // right
}

void traverseAndUpdate(TreeNode* root,vector<int> &inorder,int &index)
{
    if(root==NULL) return;

    traverseAndUpdate(root->left,inorder,index); // left
    
    root->val=inorder[index]; // root, do business
    index++;

    traverseAndUpdate(root->right,inorder,index); // right
}
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        traverse(root,inorder); // store the inorder traversal of original tree
        sort(inorder.begin(),inorder.end());
        int index=0;
        traverseAndUpdate(root,inorder,index);
    }
};