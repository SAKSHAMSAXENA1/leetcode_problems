class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> u;
        int n=s.size(),removed=0;

        for(auto c: s)
        u[c]++;

        for(auto it:u)
        {
            if(it.second>2)
            {
                if(it.second%2) removed+=it.second-1;
                else removed+=it.second-2;
            }
        }

        return n-removed;
    }
};