# define ll long long
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int,vector<int>,greater<>> pq;
        unordered_map<int,ll> u;
        int n=nums1.size();
        vector<ll> res(n,0);
        ll sum=0;

        vector<pair<int,pair<int,int>>> arr;
        for(int i=0;i<n;i++)
            {
                arr.push_back({nums1[i],{nums2[i],i}});
                // {el,{wt,index}}; 
            }
        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++)
            {
                int el=arr[i].first,wt=arr[i].second.first,index=arr[i].second.second;
                if(u.find(el)==u.end())
                {
                    res[index]=sum;
                    u[el]=sum;
                }
                else
                {
                    res[index]=u[el];
                }
                // i=no of elements which have been considered to make sum 
                if(i>=k)
                {
                    if(pq.top()<wt)
                    {
                        sum-=pq.top();
                        pq.pop();  
                    }
                }

                if(pq.size()<k)
                {
                    pq.push(wt);
                    sum+=wt;
                }
            }
        return res;
    }
};