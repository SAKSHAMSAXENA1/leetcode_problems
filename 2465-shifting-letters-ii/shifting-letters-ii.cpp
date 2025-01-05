class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> diff(n,0);

        for(auto it:shifts)
        {
            diff[it[0]]+=(it[2]==1)?1:-1;
            if(it[1]+1<n) diff[it[1]+1]-=(it[2]==1)?1:-1;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=diff[i];
            int netShift=sum;
            if(netShift>=0) netShift%=26; 
            else netShift=26-abs(netShift)%26; 
            s[i]='a'+(s[i]-'a'+netShift)%26;
        }

        return s;
    }
};