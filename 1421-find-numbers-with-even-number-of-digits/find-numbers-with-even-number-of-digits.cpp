class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;

        for(auto it:nums)
        {
            int dig=0;
            while(it)
            {
                dig++;
                it/=10;
            }

            if(dig%2==0) cnt++;
        }

        return cnt;
    }
};