class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size(),m=n*n;
        int x=0,bucket1=0,bucket0=0,cnt=0;
        vector<int> res(2);
        for(auto row:grid)
        {
            for(auto it:row) x^=it;
        }

        for(int i=1;i<=m;i++) x^=i;

        int temp=x,pos=0;

        while(temp)
        {
            if(temp%2) break;

            temp/=2;
            pos++;
        }

        int mask=1<<pos;

        for(auto row:grid)
        {
            for(auto it:row) 
            {
                if(it & mask) bucket1^=it;
                else bucket0^=it;
            }
        }

        for(int i=1;i<=m;i++)
        {
            if(i & mask) bucket1^=i;
            else bucket0^=i;
        }

        for(auto row:grid)
        {
            for(auto it:row)
            {
                if(it==bucket1) cnt++;
            }
        }

        if(cnt==2)
        {
            res[0]=bucket1;
            res[1]=bucket0;
        }
        else
        {
            res[0]=bucket0;
            res[1]=bucket1;
        }

        return res;
    }
};