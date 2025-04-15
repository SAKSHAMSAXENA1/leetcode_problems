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
TreeNode * findNode(TreeNode *root,int &start)
{
    if(root==NULL) return root; // return NULL

    if(root->val==start) return root; // root is the pointer to start node

    auto l=findNode(root->left,start);
    if(l!=NULL) return l;

    auto r=findNode(root->right,start);
    if(r!=NULL) return r;

    // else node is absent from both left and right subtrees
    return NULL;
}

void preOrder(TreeNode *root,unordered_map<TreeNode *,TreeNode *> &parent,
unordered_map<TreeNode *,bool> &vis)
{
    //if(root==NULL) return;

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
    
    int amountOfTime(TreeNode* root, int start) {
        auto startNode=findNode(root,start);
        unordered_map<TreeNode *,TreeNode *> parent;
        unordered_map<TreeNode *,bool> vis;
        preOrder(root,parent,vis);
        queue<TreeNode *> q;
        q.push(startNode); // start bfs with startNode
        vis[startNode]=true;
        int curLevel=0; // curLevel is the level the nodes of which are being processed
        int lastProcessedLevel=-1;

        while(!q.empty())
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

            lastProcessedLevel=curLevel;
            curLevel++;
        }

        return lastProcessedLevel;
    }
};