class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size(),ans=0;
        vector<int> diff(n,0);

        for(int i=0;i<n;i++)
        diff[i]=target[i];

        for(int i=n-1;i>=1;i--)
        {
            diff[i]-=diff[i-1];
            if(diff[i]>0) ans+=diff[i];
        }

        ans+=diff[0];
        return ans;
    }
};