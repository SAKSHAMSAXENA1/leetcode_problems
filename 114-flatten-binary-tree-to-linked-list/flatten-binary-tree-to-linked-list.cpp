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
    void flatten(TreeNode* root) {
        if(root==NULL) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            auto node=st.top();
            st.pop();

            if(node->right) st.push(node->right); // right
            if(node->left) st.push(node->left); // left

            node->right=(st.size()) ? st.top():NULL;
            node->left=NULL;
        }
    }
};