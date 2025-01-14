class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int i=0,n=A.size(),cnt=0;
        vector<int> c(n,0), freq(n+1,0);

        for(int i=0;i<n;i++)
        {
            freq[A[i]]++;
            if(freq[A[i]]==2) cnt++;

            freq[B[i]]++;
            if(freq[B[i]]==2) cnt++;

            c[i]=cnt;
        }

        return c;
    }
};