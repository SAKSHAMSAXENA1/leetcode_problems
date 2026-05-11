class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;

        for(auto it : nums)
        {
            vector<int> temp;

            while(it)
            {
                temp.push_back(it%10);
                it/=10;
            }

            while(!temp.empty())
            {
                res.push_back(temp.back());
                temp.pop_back();
            }
        }

        return res;
    }
};