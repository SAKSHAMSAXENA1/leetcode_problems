class Solution {
public:
    string makeFancyString(string s) {
        string res="";

        for(auto it:s)
        {
            int n=res.size();
            if(n>=2 && res[n-2]==res[n-1] && res[n-1]==it) continue;

            res.push_back(it);
        }

        return res;
    }
};