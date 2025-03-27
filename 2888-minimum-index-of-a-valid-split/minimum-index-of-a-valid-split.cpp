class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> u;
        vector<int> dominantInSuffix(n,-1);

        for(int j=n-1;j>=0;j--)
        {
            u[nums[j]]++;

            if(u[nums[j]]*2>(n-j))
            dominantInSuffix[j]=nums[j];
            else if(j+1<n && u[dominantInSuffix[j+1]]*2>(n-j))
            dominantInSuffix[j]=dominantInSuffix[j+1];
        }

        u.clear();

        for(int i=0;i<n-1;i++)
        {
            u[nums[i]]++;

            if(u[nums[i]]*2>(i+1)) // if nums[i] is dominant in range [0...i]
            {
                if(nums[i]==dominantInSuffix[i+1]) //if nums[i] is also dominant in [i+1...n-1]
                return i;
            }
        }

        return -1;
    }
};