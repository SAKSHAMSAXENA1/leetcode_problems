class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp=[&](vector<int> &a,vector<int> &b) {
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        };

        sort(people.begin(),people.end(),comp);
        int n=people.size();
        vector<vector<int>> res(n,{INT_MAX,-1});

        for(auto it:people)
        {
            int cntGTE=0;
            for(int i=0;i<n;i++)
            {
                if(res[i][0] >= it[0]) cntGTE++;

                if(cntGTE==it[1]+1) 
                {
                    // exactly 'it[1]' no of elements on left of 'i' which are GTE it[0] 
                    res[i]=it;
                    break;
                }
            }
        }

        return res;
    }
};