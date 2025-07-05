#define ll long long
class Solution {
public:
    long long numberOfWays(string s) {
        // valid cases: 0 1 0 OR 1 0 1
        ll res=0;
        int n=s.size();
        vector<int> suffixZeros(n,0);

        for(int i=n-2;i>=0;i--)
        {
            suffixZeros[i]=suffixZeros[i+1]+(s[i+1]=='0');
        }
        int prefixZeros=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                res+=(ll)prefixZeros*suffixZeros[i]; // 0 1 0
            else // s[i]=='0'
            {
                res+=(ll)(i-prefixZeros)*(n-1-i-suffixZeros[i]); // 1 0 1
                prefixZeros++;
            }  
        }

        return res;
    }
};