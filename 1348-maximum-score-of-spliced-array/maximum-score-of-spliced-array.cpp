class Solution {
public:
int maxSumOfFirstArray(vector<int> &nums1,vector<int> &nums2,int &n)
{
    vector<int> diff(n,0);

    for(int i=0;i<n;i++)
    diff[i]=nums2[i]-nums1[i];

    int sum=0,maxi=0,maxL=n,maxR=-1,left=0;

    for(int i=0;i<n;i++)
    {
        sum+=diff[i];

        if(sum > maxi)
        {
            // right=i;
            // maxR=right;
            maxL=left;
            maxR=i;
            maxi=sum;
        }

        if(sum < 0)
        {
            sum=0;
            left=i+1;
            // right=i+1;
        }
    }

    int i=0,sum1=0,sum2=0;
    for(;i<maxL;i++)
    {
        sum1+=nums1[i];
        sum2+=nums2[i];
    }

    for(;i<=maxR;i++)
    {
        sum1+=nums2[i];
        sum2+=nums1[i];
    }

    for(;i<n;i++)
    {
        sum1+=nums1[i];
        sum2+=nums2[i];
    }

    return max(sum1,sum2);
}
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        return max(maxSumOfFirstArray(nums1,nums2,n),maxSumOfFirstArray(nums2,nums1,n));
    }
};