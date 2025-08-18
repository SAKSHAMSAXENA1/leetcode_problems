class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        int curLevel=0;

        while(!q.empty())
        {
            int levelSize=q.size();

            while(levelSize--)
            {
                int cur=q.front();
                q.pop();

                if(cur==goal) return curLevel;

                for(auto it:nums)
                {
                    int next=cur+it;
                    if(0<=next && next<=1000)
                    {
                        if(vis.find(next)==vis.end())
                        {
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                    else if(next==goal) q.push(next);

                    next=cur-it;
                    if(0<=next && next<=1000)
                    {
                        if(vis.find(next)==vis.end())
                        {
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                    else if(next==goal) q.push(next);

                    next=cur ^ it;
                    if(0<=next && next<=1000)
                    {
                        if(vis.find(next)==vis.end())
                        {
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                    else if(next==goal) q.push(next);
                }
            }

            curLevel++;
        }

        return -1;
    }
};