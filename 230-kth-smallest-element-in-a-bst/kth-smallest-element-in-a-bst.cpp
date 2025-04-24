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
void preorder(TreeNode* root,priority_queue<int,vector<int>,greater<>> &pq)
{
    if(root==NULL) return;

    pq.push(root->val);       // root
    preorder(root->left,pq);  // left
    preorder(root->right,pq); // right
}
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<>> pq;
        preorder(root,pq);
        int res;

        while(k--)
        {
            res=pq.top();
            pq.pop();
        }

        return res;
    }
};