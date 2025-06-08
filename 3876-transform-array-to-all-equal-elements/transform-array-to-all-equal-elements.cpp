class Solution {
public:
bool canMake(vector<int> temp,int &k,int target,int &n)
{
    int operationsCnt=0;
    for(int i=0;i<n-1;i++)
    {
        if(temp[i]!=target)
        {
            temp[i]*=-1;
            temp[i+1]*=-1;
            operationsCnt++;
        }
    }

    return operationsCnt<=k && temp[n-1]==target;
}
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();

        if(canMake(nums,k,1,n)) return true; // check for [1 1 1 1 1 1]

        return canMake(nums,k,-1,n); // check for [-1 -1 -1 -1 -1 -1]
    }
};