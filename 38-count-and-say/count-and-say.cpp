class Solution {
public:
string f(int n,unordered_map<int,string> &dp)
{
    if(n==1) return "1"; // base case

    if(dp.find(n)!=dp.end()) return dp[n];

    string s=countAndSay(n-1);
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

    return dp[n]=res;
}
    string countAndSay(int n) {
        unordered_map<int,string> dp;
        return f(n,dp);
    }
};