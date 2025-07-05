class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string,int> u;
        int n=friends.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(id);
        vis[id]=true;
        int curLevel=0;

        while(!q.empty() && curLevel<level)
        {
            int m=q.size();

            for(int i=0;i<m;i++)
            {
                int curNode=q.front();
                q.pop();

                for(auto adjNode:friends[curNode])
                {
                    if(!vis[adjNode])
                    {
                        q.push(adjNode);
                        vis[adjNode]=true;
                    }
                }
            }

            curLevel++;
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto video:watchedVideos[node])
            u[video]++;
        }

        vector<pair<int,string>> sortedVideos;
        for(auto it:u)
        sortedVideos.push_back({it.second,it.first});

        auto comp=[&](pair<int,string> &a,pair<int,string> &b)
        {
            if(a.first==b.first) // same freq videos
            return a.second<b.second; // alphabetically smaller video first

            return a.first<b.first; // lower freq video first
        };

        sort(sortedVideos.begin(),sortedVideos.end(),comp);
        vector<string> res;
        for(auto it:sortedVideos)
        res.push_back(it.second);
        return res;
    }
};