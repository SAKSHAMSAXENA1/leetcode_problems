class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,l=0,r=0,n=nums.size();
        // jumps => no of jumps in which the next range [l..r] is reachable

        while(r<n-1)
        {
            int farthest=0; // farthest index reachable from elements of current range

            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,i+nums[i]);
            }

            l=r+1; // starting point of next range
            r=farthest; // ending point of next range
            jumps++; // all the elements of next range are reachable in 'jumps' no of jumps
        }

        // r>=n-1 : ending point of next range covers the index 'n-1'
        // so return the no of jumps in which the next range is reachable
        return jumps;
    }
};