class Solution {
public:
    int calcXor(vector<int> &a)
    {
        int res=0;

        for(auto it:a)
        res^=it;

        return res;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        if(nums1.size()%2) // nums1 has odd no of elements
        {
            res=calcXor(nums2);
        }
        if(nums2.size()%2) // nums2 has odd no of elements
        {
            res^= calcXor(nums1);
        }
        // both have even no of elements
        return res;
    }
};