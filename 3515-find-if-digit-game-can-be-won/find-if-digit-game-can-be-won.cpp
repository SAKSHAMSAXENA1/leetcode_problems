class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int aliceSingle=0,aliceDouble=0,tot=0;

        for(auto it:nums)
        {
            if(it<=9) aliceSingle+=it;
            else if(9<it && it<100) aliceDouble+=it;
            tot+=it;
        }

        return aliceSingle>(tot-aliceSingle) || aliceDouble>(tot-aliceDouble);
    }
};