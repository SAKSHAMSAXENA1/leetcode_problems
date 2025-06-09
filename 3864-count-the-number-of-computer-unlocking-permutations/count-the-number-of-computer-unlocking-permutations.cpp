class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod=(int)(1e9+7);
        int n=complexity.size();
        long res=1;

        for(int i=1;i<n;i++)
        {
            if(complexity[i]<=complexity[0]) return 0;

            res*=i;
            res%=mod;
        }

        return res;
    }
};