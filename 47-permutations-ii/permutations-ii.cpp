class Solution {
public:
void f(vector<int> &ds,vector<int> &nums,vector<bool> &used,set<vector<int>> &res,int &n)
{
    if(ds.size()==n)
    {
        res.insert(ds);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!used[i])
        {
            ds.push_back(nums[i]);
            used[i]=true;
            f(ds,nums,used,res,n);
            used[i]=false;
            ds.pop_back();
        }
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<bool> used(n,false);
        vector<int> ds;
        set<vector<int>> res;
        vector<vector<int>> ans;
        f(ds,nums,used,res,n);

        for(auto it:res)
        ans.push_back(it);

        return ans;
    }
};