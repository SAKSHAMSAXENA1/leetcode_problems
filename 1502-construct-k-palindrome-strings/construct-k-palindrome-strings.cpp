class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        unordered_map<char,int> u;
        int oddFreqCharCnt=0;

        for(auto it:s)
        u[it]++;

        for(auto it:u)
        {
            if(it.second%2) // characters with odd frequency
            oddFreqCharCnt++;
        }

        if(k<oddFreqCharCnt) return false;

        return true;
    }
};