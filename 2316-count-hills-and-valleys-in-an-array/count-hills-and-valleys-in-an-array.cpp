class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt=0,n=nums.size();

        for(int i=1;i<n;i++)
        {
            int j=i,prev=i-1,next;
            while(j+1<n && nums[j]==nums[j+1])
            j++;

            next=j+1;

            if(next==n) continue;

            if((nums[prev]<nums[j] && nums[next]<nums[j]) 
             ||(nums[j]<nums[prev] && nums[j]<nums[next]))
            cnt++;
            
            i=j;
        }

        return cnt;
    }
};