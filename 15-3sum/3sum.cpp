class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> u;
        vector<vector<int>> res;

        for(int i=0;i<=n-3;i++)
        {
            int remSum=-nums[i];
            int l=i+1,r=n-1;

            while(l<r)
            {
                int curSum=nums[l]+nums[r];

                if(curSum > remSum)
                r--; // reduce curSum so that it may become equal to remSum
                else if(curSum < remSum)
                l++; // increase curSum so that it may become equal to remSum
                else // curSum==remSum
                {
                    u.insert({nums[i],nums[l],nums[r]});

                    if(nums[l]!=nums[r])
                    {
                        while(l+1<r && nums[l]==nums[l+1]) // skip duplicates of nums[l]
                        l++;

                        while(l<r-1 && nums[r-1]==nums[r]) // skip duplicates of nums[r]
                        r--; 

                        l++; // inc nums[l] and dec nums[r] to try for other valid triplets
                        r--;
                    }
                    else // nums[l]==nums[r], l<r so we can't further inc nums[l] or dec nums[r]
                    break; 
                }
            }

            while(i+1<n && nums[i]==nums[i+1]) // skip duplicates of nums[i]
            i++;
        }

        for(auto it:u)
        res.push_back(it);

        return res;
    }
};