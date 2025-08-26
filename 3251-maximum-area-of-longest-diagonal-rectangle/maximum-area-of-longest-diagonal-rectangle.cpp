class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi=0,res=0;

        for(auto it:dimensions)
        {
            int diagonalSquare=it[0]*it[0]+it[1]*it[1];

            if(diagonalSquare > maxi)
            {
                maxi=diagonalSquare;
                res=it[0]*it[1];
            }
            else if(diagonalSquare==maxi)
            res=max(res,it[0]*it[1]);
        }

        return res;
    }
};