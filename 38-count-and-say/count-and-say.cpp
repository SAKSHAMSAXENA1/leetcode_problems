class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1"; // base case

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

        return res;
    }
};