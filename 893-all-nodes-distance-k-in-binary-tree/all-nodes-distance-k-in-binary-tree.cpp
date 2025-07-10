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
void dfs(TreeNode *root,unordered_map<int,TreeNode*> &parent)
{
    if(root->left)
    {
        parent[root->left->val]=root;
        dfs(root->left,parent);
    }

    if(root->right)
    {
        parent[root->right->val]=root;
        dfs(root->right,parent);
    }
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,TreeNode*> parent;
        dfs(root,parent);

        unordered_set<int> vis;    
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target->val);
        int curLevel=0;

        while(!q.empty() && curLevel<k)
        {
            int nodesInCurLevel=q.size();

            while(nodesInCurLevel--)
            {
                auto node=q.front();
                q.pop();

                if(node->left && vis.find(node->left->val)==vis.end())
                {
                    q.push(node->left);
                    vis.insert(node->left->val);
                }

                if(node->right && vis.find(node->right->val)==vis.end())
                {
                    q.push(node->right);
                    vis.insert(node->right->val);
                }

                if(parent.find(node->val)!=parent.end() && 
                vis.find(parent[node->val]->val)==vis.end())
                {
                    q.push(parent[node->val]);
                    vis.insert(parent[node->val]->val);
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