class Solution {
public:
int f(int startI,int startJ,vector<vector<int>> &fruits,int &n,int factor[],int di[],int dj[])
{
    queue<pair<int,pair<int,int>>> q;
    vector<vector<int>> dist(n,vector<int>(n,INT_MIN));
    q.push({0,{startI,startJ}});
    
    while(!q.empty())
    {
        int curDist=q.front().first,i=q.front().second.first,j=q.front().second.second;
        q.pop();

        if(curDist<dist[i][j]) continue;

        if(i==n-1 && j==n-1) break;

        for(int k=0;k<3;k++)
        {
            int ni=i+di[k],nj=j+dj[k];
            int remMoves=(n-1-ni)*factor[0]+(n-1-nj)*factor[1];

            if(0<=ni && ni<n && 0<=nj && nj<n && ((n-1-ni)+(n-1-nj))<=2*remMoves)
            {
                if(curDist+fruits[i][j] > dist[ni][nj])
                {
                    dist[ni][nj]=curDist+fruits[i][j];
                    q.push({dist[ni][nj],{ni,nj}});
                }
            }
        }
    }

    return dist[n-1][n-1];
}
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res=0,n=fruits.size();
        int factor1[]={1,0},factor2[]={0,1};
        int d1[]={1,1,1},d2[]={-1,0,1};

        for(int i=0;i<n;i++)
        {
            res+=fruits[i][i];
            fruits[i][i]=0;
        }

        return res+f(0,n-1,fruits,n,factor1,d1,d2)+f(n-1,0,fruits,n,factor2,d2,d1); 
    }
};