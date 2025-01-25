class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> arr;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        vector<vector<int>> groups;
        groups.push_back({arr[0].second});

        for(int i=1;i<n;i++)
        {
            if(arr[i].first-arr[i-1].first<=limit) 
            groups.back().push_back(arr[i].second);
            else
            groups.push_back({arr[i].second});
        }

        int indexArr=0;
        for(auto group: groups)
        {
            sort(group.begin(),group.end());

            for(auto index: group)
            {
                nums[index]=arr[indexArr].first;
                indexArr++;
            }
        }

        return nums;
    }
};