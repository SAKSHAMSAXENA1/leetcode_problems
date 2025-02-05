class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n!=m) return false;
        unordered_map<char,int> u;
        int cntMismatch=0;

        for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[i]) continue;

            cntMismatch++;
            u[s1[i]]++;
            u[s2[i]]--;

            if(u[s1[i]]==0) u.erase(s1[i]);
            if(u[s2[i]]==0) u.erase(s2[i]);
        }

        return u.size()==0 && cntMismatch<=2;
        
    }
};