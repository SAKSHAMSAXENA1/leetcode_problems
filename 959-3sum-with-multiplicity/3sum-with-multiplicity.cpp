#define ll long long
#define mod (int)(1e9+7)
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> u;
        int n=arr.size();
        ll res=0;

        for(auto it:arr) u[it]++;

        for(int i=0;i<=n-3;i++)
        {
            int remSum=target-arr[i];
            u[arr[i]]--;
            int l=i+1,r=n-1;

            while(l < r)
            {
                int curSum=arr[l]+arr[r];

                if(curSum > remSum) // reduce curSum so that it may become equal to remSum
                r--;
                else if(curSum < remSum) // increase curSum so that it may become equal to remSum
                l++;
                else // curSum == remSum
                {
                    while(l+1<r && arr[l]==arr[l+1])
                    l++;

                    while(l<r-1 && arr[r-1]==arr[r])
                    r--;
                    
                    if(arr[l]!=arr[r])
                    {
                        res=(res+(ll)u[arr[l]]*u[arr[r]])%mod;

                        l++;
                        r--;
                    }
                    else // arr[l]==arr[r]
                    {
                        res=(res+(ll)u[arr[l]]*(u[arr[l]]-1)/2)%mod;
                        break; // arr[l]==arr[r], l<r so we can't inc nums[l] or dec nums[r]
                    }
                }
            }
        }

        return res;
    }
};