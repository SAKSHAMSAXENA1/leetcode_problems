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
class FindElements {
public:
unordered_set<int> values;
    void f(TreeNode *root, TreeNode *absoluteRoot)
    {
        if(root==absoluteRoot) 
        {
            root->val=0;
            values.insert(root->val);
        }

        if(root->left)
        {
            int temp=2*root->val+1;
            root->left->val=temp;
            values.insert(temp);
            f(root->left,absoluteRoot);
        }

        if(root->right)
        {
            int temp=2*root->val+2;
            root->right->val=temp;
            values.insert(temp);
            f(root->right,absoluteRoot);
        }
    }
    FindElements(TreeNode* root) {
        f(root,root);
    }
    
    bool find(int target) {
        return values.find(target)!=values.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */