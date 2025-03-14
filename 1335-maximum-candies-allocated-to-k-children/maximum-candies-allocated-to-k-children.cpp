class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1,r=*max_element(candies.begin(),candies.end()),ans=0;

        while(l<=r)
        {
            int mid=(l+r)>>1; // mid=candies given to each child

            long long childrenServed=0;
            for(auto it: candies)
            childrenServed+=it/mid;

            if(childrenServed>=k)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
};