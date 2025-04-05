class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size(),roomsReached=0;
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0); // start from room 0
        vis[0]=true;
        roomsReached++;

        while(!q.empty())
        {
            int curRoom=q.front();
            q.pop();

            for(auto adjRoom:rooms[curRoom])
            {
                if(!vis[adjRoom])
                {
                    vis[adjRoom]=true;
                    roomsReached++;
                    q.push(adjRoom);
                }
            }
        }
        return roomsReached==n;
    }
};