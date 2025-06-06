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
void inorderTraversal(TreeNode* root,vector<int> &inorder)
{
    if(root==NULL) return;

    inorderTraversal(root->left,inorder); // left

    inorder.push_back(root->val); // root

    inorderTraversal(root->right,inorder); // right
}

vector<int> mergeSortedArrays(vector<int> &a,vector<int> &b)
{
    int n=a.size(),m=b.size(),i=0,j=0;
    vector<int> res;

    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            res.push_back(a[i++]);
        }
        else if(b[j]<a[i])
        {
            res.push_back(b[j++]);
        }
        else // a[i]==b[j]
        {
            res.push_back(a[i++]);
            res.push_back(b[j++]);
        }
    }

    while(i<n) res.push_back(a[i++]);

    while(j<m) res.push_back(b[j++]);

    return res;
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorder1,inorder2;
        inorderTraversal(root1,inorder1);
        inorderTraversal(root2,inorder2);

        return mergeSortedArrays(inorder1,inorder2);
    }
};