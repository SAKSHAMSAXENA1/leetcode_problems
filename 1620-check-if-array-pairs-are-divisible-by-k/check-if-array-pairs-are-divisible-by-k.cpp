class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> u;
        int cnt=0,n=arr.size();

        for(int i=0;i<n;i++)
        {
            int cur=(arr[i]<0) ? ceil(abs(arr[i])/k)*k-abs(arr[i]) : arr[i];
            int rem=(k+cur)%k;
            int complementaryRem=(k-rem)%k;
            
            if(u.find(complementaryRem)!=u.end())
            {
                cnt++;
                u[complementaryRem]--;

                if(u[complementaryRem]==0) u.erase(complementaryRem);
            }
            else
            u[rem]++;
        }

        return cnt==n/2;
    }
};