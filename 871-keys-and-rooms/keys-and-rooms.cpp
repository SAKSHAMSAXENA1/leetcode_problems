class Solution {
public:
void dfs(int i,vector<bool> &vis,vector<vector<int>>& rooms)
{
    vis[i]=true;

    for(auto adjRoom: rooms[i])
    {
        if(!vis[adjRoom])
        {
            dfs(adjRoom,vis,rooms);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size(),roomsVisited=0;
        vector<bool> vis(n, false);

        dfs(0,vis,rooms);

        for(auto it:vis)
        {
            roomsVisited+=it;
        }

        return roomsVisited==n;
    }
};