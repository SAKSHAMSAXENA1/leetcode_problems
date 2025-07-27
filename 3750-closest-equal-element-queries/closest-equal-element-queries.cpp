class Solution {
public:
int binarySearch(vector<int> &nums,int &key,int &n)
{
    int l=0,h=n-1;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(nums[mid]==key) return mid;
        else if(key<nums[mid]) // search on left
        h=mid-1;
        else // nums[mid]<key => search on right
        l=mid+1;
    }

    return -1;
}
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> u;
        vector<int> res;
        int n=nums.size();

        for(int i=0;i<n;i++)
        u[nums[i]].push_back(i);

        for(auto index: queries)
        {
            int element=nums[index];
            int m=u[element].size();
            if(m==1)
            {
                res.push_back(-1);
                continue;
            }

            int ind=binarySearch(u[element],index,m);
            int prev,next,mini;

            if(ind==0)
            {
                next=min(u[element][ind+1]-index,index+n-u[element][ind+1]); // next at ind+1
                prev=min(u[element][m-1]-ind,index+n-u[element][m-1]); // prev at m-1
                mini=min(prev,next);
            }
            else if(ind==m-1)
            {
                prev=min(index-u[element][ind-1],u[element][ind-1]+n-index); // prev at ind-1
                next=min(index-u[element][0],u[element][0]+n-index); // next at 0
                mini=min(prev,next);
            }
            else
            {
                prev=min(index-u[element][ind-1],u[element][ind-1]+n-index); // prev at ind-1
                next=min(u[element][ind+1]-index,index+n-u[element][ind+1]); // next at ind+1
                mini=min(prev,next);
            }

            res.push_back(mini);
        }

        return res;
    }
};