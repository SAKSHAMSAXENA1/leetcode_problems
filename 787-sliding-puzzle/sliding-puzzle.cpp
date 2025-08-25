class Solution {
public:
bool isSolved(vector<vector<int>> &board,int &m,int &n)
{
    int N=m*n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j] != (i*n+j+1)%N) return false;
        }
    }

    return true;
}
    int slidingPuzzle(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
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

                if(isSolved(cur,m,n)) return curLevel;

                for(int i=0;i<m;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(cur[i][j]!=0) continue;
                        // else cur[i][j]==0

                        for(int k=0;k<4;k++)
                        {
                            int ni=i+di[k],nj=j+dj[k];

                            if(0<=ni && ni<m && 0<=nj && nj<n)
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