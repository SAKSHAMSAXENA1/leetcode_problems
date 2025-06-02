class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=0,n=ratings.size();
        vector<int> cnt(n,1);

        for(int i=1;i<n;i++)
        {
            if(ratings[i-1] < ratings[i])
            cnt[i]=cnt[i-1]+1;
        }

        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            cnt[i]=max(cnt[i],cnt[i+1]+1);
        }

        for(auto it:cnt)
        sum+=it;

        return sum;
    }
};