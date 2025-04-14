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
void preOrder(TreeNode *root,unordered_map<int,vector<int>> &adj, unordered_map<int,bool> &vis)
{
    vis[root->val]=false;

    if(root->left)
    {
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
        preOrder(root->left,adj,vis);
    }

    if(root->right)
    {
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
        preOrder(root->right,adj,vis);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};

        unordered_map<int,vector<int>> adj;
        unordered_map<int,bool> vis;
        //vector<bool> vis(adj.size(), false);
        vector<int> res;
        preOrder(root,adj,vis);
        
        queue<int> q;
        q.push(target->val); // start bfs from the target node
        vis[target->val]=true;
        // when you process nodes of level 'i', you insert nodes of level 'i+1' into the queue
        int curLevel=0; 

        while(!q.empty() && curLevel<k)
        {
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                int curNode=q.front();
                q.pop();

                for(auto neighbour:adj[curNode])
                {
                    if(!vis[neighbour])
                    {
                        q.push(neighbour);
                        vis[neighbour]=true;
                    }
                }
            }

            curLevel++;
        }

        if(curLevel==k)
        {
            while(!q.empty())
            {
                res.push_back(q.front());
                q.pop();
            }
        }

        return res;
    }
};