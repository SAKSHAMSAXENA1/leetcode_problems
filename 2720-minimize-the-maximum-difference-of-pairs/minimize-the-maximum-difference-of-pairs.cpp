class Solution {
public:
bool canGetGTEpPairs(vector<int> &nums,int &n,int &maxDiff,int &p)
{
    int i=0,cnt=0;

    while(i+1<n)
    {
        if(nums[i+1]-nums[i]<=maxDiff)
        {
            cnt++;
            i+=2; // nums[i+1] paired with nums[i], so can't consider pair
            // between nums[i+1] & nums[i+2]
        }
        else // nums[i+1] is not paired with nums[i] since their diff>maxDiff
            i+=1; // so we can try to pair nums[i+1] with nums[i+2]
    }

    return cnt>=p; // we have >=p pairs where diff of each pair <=maxDiff
}
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end()); // adj elements of sorted array form pairs with min diff
        int n=nums.size();
        int l=0,h=nums[n-1]-nums[0];
        int res=0;
        
        while(l<=h)
        {
            int mid=((long)l+h)/2; 
            
            // check if we can get >=p pairs such that the diff of each pair<=mid
            if(canGetGTEpPairs(nums,n,mid,p))
            {
                res=mid;
                h=mid-1; // try for smaller values of max diff
            }
            else // can't get >=p pairs where diff of each pair<=mid
            {
                l=mid+1; // so try for a higher val of max diff
            } 
        }

        return res;
    }
};