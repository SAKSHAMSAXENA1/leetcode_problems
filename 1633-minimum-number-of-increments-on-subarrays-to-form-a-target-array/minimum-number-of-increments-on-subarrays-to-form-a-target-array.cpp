class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size(),ans=0;

        for(int i=n-1;i>=1;i--)
        {
            int diff=target[i];
            diff-=target[i-1];
            if(diff>0) ans+=diff;
        }

        ans+=target[0];
        return ans;
    }
};