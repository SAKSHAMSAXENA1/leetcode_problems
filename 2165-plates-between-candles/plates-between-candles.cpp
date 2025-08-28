class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> candleIndices,prefixCandles(n,0),res;

        for(int i=0;i<n;i++)
        {
            if(i>0) prefixCandles[i]=prefixCandles[i-1];

            if(s[i]=='|')
            {
                candleIndices.push_back(i);
                prefixCandles[i]++;
            }
        }

        for(auto it:queries)
        {
            int left=it[0],right=it[1],ans=0;
            auto ub=upper_bound(candleIndices.begin(),candleIndices.end(),right);
            auto lb=lower_bound(candleIndices.begin(),candleIndices.end(),left);

            if(ub!=candleIndices.begin() && lb!=candleIndices.end())
            {
                ub--;
                int leftIndex=*lb,rightIndex=*ub;
                if(leftIndex <= rightIndex)
                {
                    int totPositions=rightIndex-leftIndex+1;
                    int candlesInRange=
                    prefixCandles[rightIndex]-((leftIndex>0) ? prefixCandles[leftIndex-1] : 0);

                    ans=totPositions-candlesInRange;
                }
            }

            res.push_back(ans);
        }

        return res;
    }
};