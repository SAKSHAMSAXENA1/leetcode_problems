#define ll long long
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        ll res=0;
        int n=nums.size();

        int prev=0;
        for(int i=0;i<n;i++)
        {
            int cur=target[i]-nums[i];

            if((prev<0 && 0<cur) || (cur<0 && 0<prev)) // sign change
            {
                res+=abs(cur); // move from level 0 directly to cur level
            }
            else if(abs(cur) > abs(prev)) // both cur and prev of the same sign/no sign change
            {
                res+=abs(cur-prev);
            }

            prev=cur;
        }

        return res;
    }
};