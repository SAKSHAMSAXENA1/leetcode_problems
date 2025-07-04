class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res;
        vector<int> P;

        for(int i=0;i<m;i++) P.push_back(i+1);

        for(auto it:queries)
        {
            for(int i=0;i<m;i++)
            {
                if(it==P[i])
                {
                    res.push_back(i);
                    P.erase(P.begin()+i);
                    P.insert(P.begin(),it);
                }
            }
        }

        return res;
    }
};