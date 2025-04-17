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
TreeNode* construct(vector<int> &preorder, vector<int> &inorder,int preStart,int preEnd,
int inStart,int inEnd,unordered_map<int,int> &index)
{
    if(preEnd<preStart || inEnd<inStart) return NULL;

    int preRoot=preorder[preStart];
    int inRootIndex=index[preRoot];
    int cntLeftElements=inRootIndex-inStart;
    int cntRightELements=inEnd-inRootIndex;

    TreeNode* root=new TreeNode(preRoot);

    root->left=construct(preorder,inorder,preStart+1,preStart+cntLeftElements,inStart,
    inRootIndex-1,index);

    root->right=construct(preorder,inorder,preStart+cntLeftElements+1,preEnd,inRootIndex+1,inEnd,
    index);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> index;
        int n=preorder.size();
        
        for(int i=0;i<n;i++) index[inorder[i]]=i;

        return construct(preorder,inorder,0,n-1,0,n-1,index);
    }
};