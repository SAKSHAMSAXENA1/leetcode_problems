class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxi=0;
        int res=0;

        for(auto it:dimensions)
        {
            double diagonal=sqrt(1.0*it[0]*it[0]+it[1]*it[1]);

            if(diagonal > maxi)
            {
                maxi=diagonal;
                res=it[0]*it[1];
            }
            else if(diagonal==maxi)
            res=max(res,it[0]*it[1]);
        }

        return res;
    }
};