class Solution {
public:
int f1(vector<int> &nums)
{
    int l=0,r=nums.size()-1,res=nums.size();
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(0<nums[mid])
        {
            res=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return res;
}

int f2(vector<int> &nums)
{
    int l=0,r=nums.size()-1,res=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(nums[mid]<0)
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    return res;
}
    int maximumCount(vector<int>& nums) {
        int firstPositive=f1(nums);
        cout<<firstPositive<<endl;
        int lastNegative=f2(nums);
        cout<<lastNegative;
        int n=nums.size();
        return max(n-firstPositive,lastNegative+1);
    }
};