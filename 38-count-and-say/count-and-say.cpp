class Solution {
public:
    string countAndSay(int n) {
        string prev;
        prev="1"; // base case

        for(int k=2;k<=n;k++)
        {
            string res=""; // res is rle, cur=res
            int m=prev.size();

            for(int i=0;i<m;i++)
            {
                int j=i+1;
                while(j<m && prev[i]==prev[j])
                j++;

                string count=to_string(j-i);
                res.append(count);
                res.push_back(prev[i]);
                i=j-1;
            }

            prev=res;
        }

        return prev;
    }
};