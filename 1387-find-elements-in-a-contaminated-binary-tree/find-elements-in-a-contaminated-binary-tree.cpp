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
void initialise(TreeNode *root,int value)
{
    root->val=value;
    values.insert(value);

    if(root->left) initialise(root->left,2*value+1);

    if(root->right) initialise(root->right,2*value+2); 
}
    FindElements(TreeNode* root) {
        initialise(root,0);
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