class Solution {
public:
    string countAndSay(int n) {
        unordered_map<int,string> dp;
        dp[1]="1"; // base case

        for(int k=2;k<=n;k++)
        {
            string s=dp[k-1];
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

            dp[k]=res;
        }

        return dp[n];
    }
};