class Solution {
public:
bool isSolved(vector<vector<int>> &board)
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] != (i*3+j+1)%6) return false;
        }
    }

    return true;
}
    int slidingPuzzle(vector<vector<int>>& board) {
        int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
        set<vector<vector<int>>> vis;
        queue<vector<vector<int>>> q;
        q.push(board);
        vis.insert(board);
        int curLevel=0;

        while(!q.empty())
        {
            int levelSize=q.size();
            while(levelSize--)
            {
                auto cur=q.front();
                q.pop();

                if(isSolved(cur)) return curLevel;

                for(int i=0;i<2;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(cur[i][j]!=0) continue;
                        // else cur[i][j]==0

                        for(int k=0;k<4;k++)
                        {
                            int ni=i+di[k],nj=j+dj[k];

                            if(0<=ni && ni<2 && 0<=nj && nj<3)
                            {
                                swap(cur[i][j],cur[ni][nj]); // do

                                if(vis.find(cur)==vis.end()) // explore
                                {
                                    vis.insert(cur);
                                    q.push(cur);
                                }

                                swap(cur[i][j],cur[ni][nj]); // undo
                            }
                        }  
                    }
                }
            }
            curLevel++;
        }

        return -1;
    }
};