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
void dfs(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent)
{
    if(root->left)
    {
        parent[root->left]=root;
        dfs(root->left,parent);
    }

    if(root->right)
    {
        parent[root->right]=root;
        dfs(root->right,parent);
    }
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        dfs(root,parent);

        unordered_set<TreeNode*> vis;    
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);
        int curLevel=0;

        while(!q.empty() && curLevel<k)
        {
            int nodesInCurLevel=q.size();

            while(nodesInCurLevel--)
            {
                auto node=q.front();
                q.pop();

                if(node->left && vis.find(node->left)==vis.end())
                {
                    q.push(node->left);
                    vis.insert(node->left);
                }

                if(node->right && vis.find(node->right)==vis.end())
                {
                    q.push(node->right);
                    vis.insert(node->right);
                }

                if(parent.find(node)!=parent.end() && vis.find(parent[node])==vis.end())
                {
                    q.push(parent[node]);
                    vis.insert(parent[node]);
                }
            }

            curLevel++;
        }

        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};