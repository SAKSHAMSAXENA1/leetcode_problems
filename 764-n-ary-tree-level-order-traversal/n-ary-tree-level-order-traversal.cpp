/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize=q.size();
            vector<int> temp;

            while(levelSize--)
            {
                auto cur=q.front();
                q.pop();

                temp.push_back(cur->val);

                for(auto nbr: cur->children)
                {
                    q.push(nbr);
                }
            }

            res.push_back(temp);
        }

        return res;
    }
};