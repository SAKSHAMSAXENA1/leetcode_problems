class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,pair<int,int>> u;
        int n=s.size(),res=0;

        for(char c='a';c<='z';c++)
        {
            u[c]={-1,-1};
        }

        for(int i=0;i<n;i++)
        {
            if(u[s[i]].first==-1) 
            {
                u[s[i]].first=i;
            }

            u[s[i]].second=i;
        }

        for(auto it:u)
        {
            int start=it.second.first,end=it.second.second;
            unordered_set<char> st;
            for(int j=start+1;j<end;j++)
            st.insert(s[j]);

            res+=st.size();
        }

        return res;   
    }
};