class Solution {
public:
    int maximum69Number (int num) {
        string nums=to_string(num);

        for(auto &c: nums)
        {
            if(c=='6')
            {
                c='9';
                break;
            }
        }

        return stoi(nums);

    }
};