class Solution {
public:
int f(vector<int> &arr,int idx,int &x)
{
    int res=0;
    for(auto it:arr)
    {
        if(abs(it-arr[idx])%x) return -1;

        res+=abs(it-arr[idx])/x;
    }

    return res;
}
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size();
        vector<int> arr;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        arr.push_back(grid[i][j]);

        sort(arr.begin(),arr.end());

        if((m*n)%2) return f(arr,(m*n)/2,x); // odd no of elements, so 1 median element

        int ans1=f(arr,(m*n)/2-1,x);
        int ans2=f(arr,(m*n)/2,x);

        if(ans1==-1) return ans2;
        else if(ans2==-1) return ans1;
        else return min(ans1,ans2);
    }
};