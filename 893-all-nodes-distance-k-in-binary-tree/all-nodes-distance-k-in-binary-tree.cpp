/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void preOrder(TreeNode *root,unordered_map<TreeNode *,TreeNode *> &parent,
unordered_map<TreeNode *,bool> &vis)
{
    if(root==NULL) return;

    vis[root]=false;
    if(root->left)
    {
        parent[root->left]=root;
        preOrder(root->left,parent,vis);
    }

    if(root->right)
    {
        parent[root->right]=root;
        preOrder(root->right,parent,vis);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> parent;
        unordered_map<TreeNode *,bool> vis;
        vector<int> res;
        preOrder(root,parent,vis);

        queue<TreeNode *> q;
        q.push(target);
        vis[target]=true;
        int curLevel=0;

        while(!q.empty() && curLevel<k)
        {
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                auto curNode=q.front();
                q.pop();

                if(curNode->left && !vis[curNode->left])
                {
                    q.push(curNode->left);
                    vis[curNode->left]=true;
                }

                if(curNode->right && !vis[curNode->right])
                {
                    q.push(curNode->right);
                    vis[curNode->right]=true;
                }

                if(parent.find(curNode)!=parent.end() && !vis[parent[curNode]])
                {
                    q.push(parent[curNode]);
                    vis[parent[curNode]]=true;
                }
            }

            curLevel++;
        }

        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};