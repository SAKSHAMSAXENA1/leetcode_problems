class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff=INT_MAX,res=0,n=nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            int remSum=target-nums[i];
            int l=i+1,r=n-1;
            bool perfectAnsFound=false;

            while(l<r)
            {
                int curSum=nums[l]+nums[r];

                int diff=abs(curSum-remSum);

                if(diff<minDiff)
                {
                    minDiff=diff;
                    res=nums[i]+nums[l]+nums[r];
                }

                if(curSum > remSum) r--;
                else if(curSum < remSum) l++;
                else // curSum==remSum
                {
                    perfectAnsFound=true;
                    break;
                }
            }

            if(perfectAnsFound==true) break;
        }

        return res;
    }
};