class Solution {
public:
int f(int i,int xorVal,vector<int> &nums,int &n)
{
    if(i==n) return xorVal;
    // take
    int take=f(i+1,xorVal^nums[i],nums,n);

    // notTake
    int notTake=f(i+1,xorVal,nums,n);

    return take+notTake;
}
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return f(0,0,nums,n);
    }
};