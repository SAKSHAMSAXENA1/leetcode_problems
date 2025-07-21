class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int curLevel=0;

        while(!q.empty())
        {
            int nodesInCurLevel=q.size();

            while(nodesInCurLevel--)
            {
                int curIndex=q.front();
                q.pop();

                if(curIndex==n-1) return curLevel;

                for(int jumps=1;jumps<=nums[curIndex] && curIndex+jumps<n;jumps++)
                {
                    int nextIndex=curIndex+jumps;

                    if(!vis[nextIndex])
                    {
                        q.push(nextIndex);
                        vis[nextIndex]=true;
                    }
                }
            }

            curLevel++;
        }

        return -1;
    }
};