class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n,0);
        int k=1;

        for(int i=0;i+1<n;i+=2)
        {
            res[i]=k;
            res[i+1]=-k;
            k++;
        }

        return res;
    }
};