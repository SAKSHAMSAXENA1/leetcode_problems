class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> visInB(n,false);
        vector<int> res(n);

        for(int i = 0; i< n;i++)
        {
            visInB[B[i]] = true;
            int cnt = 0;

            for(int j = 0; j<=i;j++)
            {
                cnt += visInB[A[j]];
            }

            res[i] = cnt;
        }

        return res;
    }
};