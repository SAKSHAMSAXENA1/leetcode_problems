class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flattened;
        int n=grid.size(),m=grid[0].size(),res=0;

        // step 1-> flatten
        for(int i=0;i<n;i++)
        {
            for(auto it:grid[i])
            flattened.push_back(it);
        }

        // step 2-> sort
        sort(flattened.begin(),flattened.end());
        int medianIndex=n*m/2;
        int commonVal=flattened[medianIndex]; // commonVal is the median element of flattened

        for(auto it:flattened)
        {
            if(it%x!=commonVal%x)  // indicates if conversion is not possible
            return -1;

            res+=abs(commonVal-it)/x;
        }

        return res;
    }
};