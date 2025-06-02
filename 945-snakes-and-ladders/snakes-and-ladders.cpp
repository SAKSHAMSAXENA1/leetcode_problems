class Solution {
public:
pair<int,int> getCoordinates(int &cell,int &n)
{
    int rowFromTop=(cell-1)/n;
    int col=(cell-1)%n;

    if(rowFromTop%2) // odd row -> filling of cells in reverse dirn (right to left)
    col=n-1-col;

    int rowFromBottom=n-1-rowFromTop;

    return {rowFromBottom,col};
}
    int snakesAndLadders(vector<vector<int>>& board) {
        // min no of steps to reach destination from src -> bfs
        int n=board.size();
        vector<bool> vis(n*n+1,false);
        queue<int> q;
        q.push(1); // start bfs from cell 1
        vis[1]=true;
        int level=0; // diceRollsDone

        while(!q.empty())
        {
            int cellsInCurLevel=q.size();

            for(int i=0;i<cellsInCurLevel;i++)
            {
                int curCell=q.front();
                q.pop();

                if(curCell==n*n) return level; // diceRollsDone

                for(int nextCell=curCell+1;nextCell<=min(curCell+6,n*n);nextCell++)
                {
                    auto [row,col]=getCoordinates(nextCell,n);
                    int destinationCell=nextCell;

                    if(board[row][col]!=-1) // nextCell points to some other cell
                    {
                        destinationCell=board[row][col];
                    }

                    if(!vis[destinationCell])
                    {
                        q.push(destinationCell);
                        vis[destinationCell]=true;
                    }
                }
            }

            level++; // diceRollsDone++
        }

        return -1; // last cell can never be reached
    }
};