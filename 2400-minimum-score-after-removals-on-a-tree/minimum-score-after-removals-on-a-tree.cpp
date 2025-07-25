class Solution {
public:
void dfs(int node,int parent,vector<vector<int>> &adj,int &timer,vector<int> &inTime,
vector<int> &outTime, vector<int> &subTreeXor, vector<int> &nums)
{
    subTreeXor[node]=nums[node];
    inTime[node]=timer;
    timer++;

    for(auto neighbour:adj[node])
    {
        if(neighbour!=parent)
        {
            dfs(neighbour,node,adj,timer,inTime,outTime,subTreeXor,nums);
            subTreeXor[node]^=subTreeXor[neighbour];
        }
    }

    outTime[node]=timer;
    timer++;
}

bool isAncestor(int &u,int &v,vector<int> &inTime,vector<int> &outTime)
{
    return inTime[u]<=inTime[v] && outTime[v]<=outTime[u];
}
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>> adj(n,vector<int>());

        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> inTime(n,0),outTime(n,0),subTreeXor(n,0);
        // subTreeXor[i]=xor of subtree rooted at node 'i'

        int timer=0,res=INT_MAX;
        // node 0 is arbitrarily taken as the root node of the entire tree
        // subTreeXor[0]=xor of subtree rooted at node '0'
        //              =xor of entire tree, since the entire tree is rooted at node '0'
        dfs(0,-1,adj,timer,inTime,outTime,subTreeXor,nums);

        for(int a=1;a<n;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                int xor1,xor2,xor3;

                if(isAncestor(a,b,inTime,outTime)) // a is ancestor of b
                {
                    xor2=subTreeXor[b];
                    xor1=subTreeXor[a] ^ xor2;
                }
                else if(isAncestor(b,a,inTime,outTime)) // b is ancestor of a
                {
                    xor2=subTreeXor[a];
                    xor1=subTreeXor[b] ^ xor2;
                }
                else 
                {
                    xor1=subTreeXor[a];
                    xor2=subTreeXor[b];
                }

                xor3=subTreeXor[0] ^ xor1 ^ xor2;

                int score=max({xor1,xor2,xor3})-min({xor1,xor2,xor3});
                res=min(res,score);
            }
        }

        return res;
    }
};