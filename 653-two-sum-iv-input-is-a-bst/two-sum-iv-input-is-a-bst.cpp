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
 class BSTIterator{
    public:
    stack<TreeNode*> st;
    bool reverse;

    void pushAll(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            if(reverse==true)
                root=root->right;
            else
                root=root->left;
        }
    }

    BSTIterator(TreeNode* root, bool isReverse)
    {
        reverse=isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* topNode=st.top();
        st.pop();

        if(reverse==true)
            pushAll(topNode->left);
        else
            pushAll(topNode->right);

        return topNode->val;
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator ascending(root,false),descending(root,true);
        int i=ascending.next();
        int j=descending.next(); // ascending.before() or ascending.reverseNext

        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j<k) i=ascending.next();
            else j=descending.next();
        }

        return false;
    }
};