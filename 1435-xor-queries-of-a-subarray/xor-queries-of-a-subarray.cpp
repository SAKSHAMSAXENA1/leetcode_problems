class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prefix(n),res;
        prefix[0]=arr[0];

        for(int i=1;i<n;i++)
        prefix[i]=arr[i] ^ prefix[i-1];

        for(auto it:queries)
        {
            int l=it[0],r=it[1];
            int val=prefix[r] ^ ((l>0) ? prefix[l-1] : 0);
            res.push_back(val);
        }

        return res;
    }
};