class Solution {
public:
    int minJumps(vector<int>& arr) {
        int dNode[2]={-1,1};
        unordered_map<int,vector<int>> adj;
        int n = arr.size();

        for(int i=0;i<n;i++)
        adj[arr[i]].push_back(i);
        
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int curLevel = 0;

        while(!q.empty())
        {
            int levelSize = q.size();

            while(levelSize--)
            {
                int curNode = q.front();
                q.pop();

                if(curNode==n-1) return curLevel;

                for(int k = 0; k < 2;k++)
                {
                    int nextNode = curNode + dNode[k];

                    if(0<=nextNode && nextNode<n && !vis[nextNode])
                    {
                        q.push(nextNode);
                        vis[nextNode] = true;
                    }
                }
                
                if(adj.find(arr[curNode]) != adj.end())
                {
                    for(auto &nextNode : adj[arr[curNode]])
                    {
                        if(!vis[nextNode])
                        {
                            q.push(nextNode);
                            vis[nextNode] = true;
                        }
                    }

                    adj.erase(arr[curNode]);
                }
            }

            curLevel++;
        }

        return -1;
    }
};