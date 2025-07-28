class Solution {
public:
void f(int index,int orVal,vector<int> &nums,int &n,int &maxi,int &cnt)
{
    if(index==n)
    {
        if(orVal>maxi)
        {
            maxi=orVal;
            cnt=1; // reset cnt to 1
        }
        else if(orVal==maxi)
        {
            cnt++; // increase cnt val
        }

        return;
    }

    // take
    f(index+1,orVal | nums[index],nums,n,maxi,cnt);

    // notTake
    f(index+1,orVal,nums,n,maxi,cnt);
}
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0,cnt=0,n=nums.size();
        f(0,0,nums,n,maxi,cnt);
        return cnt;
    }
};