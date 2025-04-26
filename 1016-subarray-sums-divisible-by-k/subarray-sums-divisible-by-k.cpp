class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> remainderCnt;
        remainderCnt[0]=1;
        int res=0,sum=0;

        for(auto it:nums)
        {
            sum+=it;
            int remainder;
            if(sum<0)
                remainder=(k-abs(sum)%k)%k;
            else 
                remainder=sum%k;
            res+=remainderCnt[remainder];
            remainderCnt[remainder]++;
        }
        
        return res;
    }
};