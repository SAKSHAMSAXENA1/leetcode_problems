class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        //unordered_set<int> allNumbers(nums.begin(),nums.end());
        unordered_map<int,int> u,cnt;
        int res=0,n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //if(i==j) continue;

                //if(u.find(nums[i]*nums[j])==u.end()) 
                u[nums[i]*nums[j]]++;
                
                //cnt[nums[i]*nums[j]]=0;
            }
        }

        for(auto it:u)
        {
            res+=(it.second)*(it.second-1)*8/2;
        }

        return res;
    }
};