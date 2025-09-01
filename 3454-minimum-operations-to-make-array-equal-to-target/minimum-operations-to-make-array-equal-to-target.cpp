#define ll long long
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        ll res=0;
        int n=nums.size();
        vector<int> diff(n,0);

        for(int i=0;i<n;i++)
        diff[i]=target[i]-nums[i];

        for(int i=n-1;i>=0;i--)
        {
            int cur=diff[i];
            if(i>0) cur=cur-diff[i-1]; // offset from prev element

            if((cur<0 && diff[i]>0) || (diff[i]<0 && cur>0)) // offset to restore, ignore
            continue;

            res+=(ll)min(abs(diff[i]),abs(cur));
        }

        return res;
    }
};