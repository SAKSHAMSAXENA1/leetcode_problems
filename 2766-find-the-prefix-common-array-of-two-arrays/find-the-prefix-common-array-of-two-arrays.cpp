class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> u;
        int i=0,n=A.size();
        vector<int> c(n,0);

        for(int i=0;i<n;i++)
        {
            u[A[i]]+=100;
            u[B[i]]-=50;

            for(auto it: u)
            {
                if(it.second==50) c[i]++;
            }
        }

        return c;
    }
};