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
TreeNode* makeTree(vector<int> &nums,int start,int end)
{
    if(end<start) return NULL;

    int index=-1,maxi=-1;
    for(int i=start;i<=end;i++)
    {
        if(nums[i]>maxi)
        {
            maxi=nums[i];
            index=i;
        }
    }

    TreeNode* node=new TreeNode(nums[index]);
    node->left=makeTree(nums,start,index-1);
    node->right=makeTree(nums,index+1,end);

    return node;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return makeTree(nums,0,nums.size()-1);
    }
};