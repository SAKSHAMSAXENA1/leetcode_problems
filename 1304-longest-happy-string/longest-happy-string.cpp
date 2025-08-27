class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res="";
        priority_queue<pair<int,char>> pq;
        if(a>0)
        pq.push({a,'a'});

        if(b>0)
        pq.push({b,'b'});

        if(c>0)
        pq.push({c,'c'});

        while(!pq.empty())
        {
            auto [curFreq,curChar]=pq.top();
            pq.pop();
            int n=res.size();

            if(n>=2 && res[n-2]==res[n-1] && res[n-1]==curChar) // curChar can't be used
            {
                // use 2nd most freq char as filler char

                if(pq.empty()) break; // no filler char available

                auto [nextFreq,nextChar]=pq.top();
                pq.pop();

                res.push_back(nextChar);
                nextFreq--;

                if(nextFreq>0)
                pq.push({nextFreq,nextChar});
            }
            else // curChar can be used
            {
                res.push_back(curChar);
                curFreq--;
            }

            if(curFreq>0)
            pq.push({curFreq,curChar});
        }

        return res;
    }
};