#define ll long long
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        ll res=0;
        int n=nums.size();

        for(int i=n-1;i>=0;i--)
        {
            int curDiff=target[i]-nums[i]; // diff[i]
            int offset=curDiff;
            if(i>0)  
            {
                int prevDiff=target[i-1]-nums[i-1]; // diff[i-1]
                offset=offset-prevDiff; // offset from prev element
            }

            if((offset<0 && curDiff>0) || (curDiff<0 && offset>0)) // offset to restore, ignore
            continue;

            res+=(ll)min(abs(curDiff),abs(offset));
        }

        return res;
    }
};