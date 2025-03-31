#define ll long long
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size(),totPairs=n-1;
        ll maxSum=0,minSum=0;
        vector<int> pairSums(totPairs);

        for(int i=0;i<totPairs;i++)
        {
            pairSums[i]=weights[i]+weights[i+1];
        }

        sort(pairSums.begin(),pairSums.end());

        for(int i=0;i<k-1;i++)
        {
            minSum+=(ll)pairSums[i];
            maxSum+=(ll)pairSums[totPairs-1-i];
        }

        return maxSum-minSum;
    }
};