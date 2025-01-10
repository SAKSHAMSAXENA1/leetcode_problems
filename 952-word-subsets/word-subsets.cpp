class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size();
        unordered_map<char,int> b;
        vector<unordered_map<char,int>> a(n);
        vector<string> res;

        for(auto it: words2)
        {
            unordered_map<char,int> temp;
            for(auto c: it)
            {
                temp[c]++;
                b[c]=max(b[c],temp[c]);
            }   
        }

        for(int i=0;i<n;i++)
        {
            for(auto c: words1[i])
            a[i][c]++;
        }

        for(int i=0;i<n;i++)
        {
            bool flag=true;
            for(auto it:b)
            {
                if(it.second>a[i][it.first]) flag=false;
            }

            if(flag) res.push_back(words1[i]);
        }

        return res;        
    }
};