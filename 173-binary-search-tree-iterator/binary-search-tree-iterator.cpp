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
class BSTIterator {
public:
vector<int> inorder;
vector<int>::iterator it;
void traversal(TreeNode* root)
{
    if(root==NULL) return;

    traversal(root->left); // left

    inorder.push_back(root->val); // root

    traversal(root->right); // right
}
    BSTIterator(TreeNode* root) {
        traversal(root); // inorder array gets populated
        it=inorder.begin(); // it initiaised 
    }
    
    int next() {
        int nextElement=*it;
        it++;
        return nextElement;
    }
    
    bool hasNext() {
        return it!=inorder.end();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */