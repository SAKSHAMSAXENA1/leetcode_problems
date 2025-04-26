#define ll long long
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // variant of subarray sum divisible by k 
        unordered_map<int,int> remainderCnt;
        vector<int> prefixCnt;
        remainderCnt[0]=1;
        int cnt=0; // cumulative/floating count of elements 
        ll res=0;

        for(auto num:nums)
        {
            int remainder=num%modulo;
            cnt+=(remainder==k);
            prefixCnt.push_back(cnt);

            /*if(k==0) // for k=0, this probm is same as subarray sum divisible by k
            res+=remainderCnt*/
        }

        for(auto it: prefixCnt)
        {
            int remainder=it%modulo;
            if(remainder-k<0)
                res+=remainderCnt[modulo-abs(remainder-k)%modulo];
            else
                res+=remainderCnt[remainder-k];

            remainderCnt[remainder]++;
        }

        return res;
    }
};