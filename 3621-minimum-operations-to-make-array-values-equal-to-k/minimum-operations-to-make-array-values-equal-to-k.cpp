class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(auto it:nums)
        {
            if(it<k) return -1;
            else if(it>k) s.insert(it);
        }

        return s.size();
    }
};