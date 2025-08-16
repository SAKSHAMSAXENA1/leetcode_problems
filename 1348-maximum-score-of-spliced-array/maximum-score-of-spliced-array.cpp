class Solution {
public:
int maxSumOfFirstArray(vector<int> &nums1,vector<int> &nums2,int &n)
{
    vector<int> diff(n,0);

    for(int i=0;i<n;i++)
    diff[i]=nums2[i]-nums1[i];

    int sum=0,maxi=0,maxL=n,maxR=-1,left=0;

    // kadane's algo
    for(int i=0;i<n;i++)
    {
        sum+=diff[i];

        if(sum > maxi)
        {
            maxL=left;
            maxR=i;
            maxi=sum;
        }

        if(sum < 0)
        {
            sum=0;
            left=i+1;
        }
    }

    
    int sum1=0;
    for(int i=0;i<n;i++)
    {
        sum1+=(maxL<=i && i<=maxR) ? nums2[i] : nums1[i];
    }

    return sum1;
}
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        return max(maxSumOfFirstArray(nums1,nums2,n),maxSumOfFirstArray(nums2,nums1,n));
    }
};