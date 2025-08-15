#define ll long long
class Solution {
public:
int binarySearch(vector<int> &a,int &m,int &key)
{
    int l=0,h=m-1;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(a[mid]==key) return mid;
        else if(key < a[mid]) h=mid-1;
        else l=mid+1;
    }

    return -1;
}
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> u;
        unordered_map<int,vector<ll>> prefixSum,suffixSum;
        vector<ll> res;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            u[nums[i]].push_back(i);
        }

        for(auto &[el,vec]:u)
        {
            int m=vec.size();
            if(m==1) continue;
            prefixSum[el].resize(m);
            suffixSum[el].resize(m);

            prefixSum[el][0]=vec[0];
            for(int i=1;i<m;i++)
            prefixSum[el][i]=prefixSum[el][i-1]+vec[i];

            suffixSum[el][m-1]=vec[m-1];
            for(int i=m-2;i>=0;i--)
            suffixSum[el][i]=suffixSum[el][i+1]+vec[i];
        }

        for(int i=0;i<n;i++)
        {
            int m=u[nums[i]].size();
            ll sum=0;
            if(m!=1) 
            {
                int idx=binarySearch(u[nums[i]],m,i);

                if(idx!=0) sum+=(ll)i*idx-prefixSum[nums[i]][idx-1];

                if(idx+1<m) sum+=suffixSum[nums[i]][idx+1]-(ll)i*(m-idx-1);
            }

            res.push_back(sum);
        }

        return res;
    }
};