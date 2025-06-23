class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            string temp=nums[i];
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                temp.append(nums[j]);
                cnt+=(temp==target);
                temp=nums[i];
            }
        }

        return cnt;
    }
};