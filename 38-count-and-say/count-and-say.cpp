class Solution {
public:
string f(int i,unordered_map<int,string> &dp)
{
    if(i==1) return "1"; // base case

    if(dp.find(i)!=dp.end()) return dp[i];

    string s=f(i-1,dp);
    string res=""; // res is rle
    int m=s.size();

    for(int i=0;i<m;i++)
    {
        int j=i+1;
        while(j<m && s[i]==s[j])
        j++;

        string count=to_string(j-i);
        res.append(count);
        res.push_back(s[i]);
        i=j-1;
    }

    return dp[i]=res;
}
    string countAndSay(int n) {
        unordered_map<int,string> dp;
        /*dp[1]="1"; // base case

        for(int i=2;i<=n;i++)
        {
            
        }*/
        return f(n,dp);
    }
};