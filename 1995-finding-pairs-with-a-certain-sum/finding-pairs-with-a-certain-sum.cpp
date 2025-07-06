class FindSumPairs {
public:
unordered_map<int,int> freq1,freq2;
vector<int> nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums2=nums2;
        for(auto it:nums1) freq1[it]++;

        for(auto it:nums2) freq2[it]++;
    }
    
    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index]+=val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int res=0;
        for(auto it:freq2)
        {
            int nums2El=it.first;
            int nums1El=tot-nums2El;
            res+=it.second*freq1[nums1El];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */