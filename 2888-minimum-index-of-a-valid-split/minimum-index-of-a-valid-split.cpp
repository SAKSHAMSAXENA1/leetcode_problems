class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> map1,map2;
        int n=nums.size();

        for(int j=n-1;j>=0;j--)
        map2[nums[j]]++;

        for(int i=0;i<n;i++)
        {
            map1[nums[i]]++; // inclusion of nums[i] in left subarray->map1
            map2[nums[i]]--; // removal of nums[i] from right subarray->map2

            int n1=i+1,n2=n-i-1;
            if(map1[nums[i]]*2>n1 && map2[nums[i]]*2>n2)
            return i;
        }

        return -1;
    }
};