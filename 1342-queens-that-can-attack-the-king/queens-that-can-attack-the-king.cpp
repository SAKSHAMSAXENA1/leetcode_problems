class Solution {
public:
bool checkInSameRow(int i,int jq,int jk,vector<vector<bool>> &grid)
{
    bool canAttack=true;
    if(jq < jk)
    {
        for(int j=jq+1;j<jk;j++)
        {
            if(grid[i][j]==true)
            {
                canAttack=false;
                break;
            }
        }
    }
    else // jk < jq
    {
        for(int j=jq-1;j>jk;j--)
        {
            if(grid[i][j]==true)
            {
                canAttack=false;
                break;
            }
        }
    }

    return canAttack;
}

bool checkInSameCol(int iq,int j,int ik,vector<vector<bool>> &grid)
{
    bool canAttack=true;
    if(iq < ik)
    {
        for(int i=iq+1;i<ik;i++)
        {
            if(grid[i][j]==true)
            {
                canAttack=false;
                break;
            }
        }
    }
    else // ik < iq
    {
        for(int i=iq-1;i>ik;i--)
        {
            if(grid[i][j]==true)
            {
                canAttack=false;
                break;
            }
        }
    }

    return canAttack;
}

bool checkInSameDiagonal(int iq,int jq,int ik,int jk,vector<vector<bool>> &grid)
{
    bool canAttack=true;
    int rel=iq-jq;
    if(iq-jq==ik-jk)
    {
        if(iq < ik) // move south-east
        {
            for(int i=iq+1;i<ik;i++)
            {
                int j=i-rel;
                if(grid[i][j])
                {
                    canAttack=false;
                    break;
                }
            }
        }
        else // move north-west
        {
            for(int i=iq-1;i>ik;i--)
            {
                int j=i-rel;
                if(grid[i][j])
                {
                    canAttack=false;
                    break;
                }
            }
        }

        return canAttack;
    }
    
    rel=iq+jq;
    if(iq+jq==ik+jk)
    {
        if(iq < ik) // move south-west
        {
            for(int i=iq+1;i<ik;i++)
            {
                int j=rel-i;
                if(grid[i][j])
                {
                    canAttack=false;
                    break;
                }
            }
        }
        else // move north-east
        {
            for(int i=iq-1;i>ik;i--)
            {
                int j=rel-i;
                if(grid[i][j])
                {
                    canAttack=false;
                    break;
                }
            }
        }

        return canAttack;
    }

    return false;
}
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n=8;
        vector<vector<bool>> grid(n,vector<bool>(n,false));
        vector<vector<int>> res;

        for(auto it:queens)
        {
            int i=it[0],j=it[1];
            grid[i][j]=true;
        }

        int ik=king[0],jk=king[1];
        for(auto it:queens)
        {
            int iq=it[0],jq=it[1];

            if(ik==iq && checkInSameRow(iq,jq,jk,grid))
                res.push_back({iq,jq});
            else if(jk==jq && checkInSameCol(iq,jq,ik,grid))
                res.push_back({iq,jq});
            else if(checkInSameDiagonal(iq,jq,ik,jk,grid))
                res.push_back({iq,jq});
            
        }

        return res;
    }
};