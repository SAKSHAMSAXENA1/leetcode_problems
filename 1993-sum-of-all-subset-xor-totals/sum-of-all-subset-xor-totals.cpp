class Solution {
public:
void f(int i,int xorVal,int &sum,vector<int> &nums,int &n)
{
    if(i==n)
    {
        sum+=xorVal;
        return;
    }

    // take
    f(i+1,xorVal^nums[i],sum,nums,n);

    // notTake
    f(i+1,xorVal,sum,nums,n);
}
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size(),sum=0;;
        f(0,0,sum,nums,n);
        return sum;
    }
};