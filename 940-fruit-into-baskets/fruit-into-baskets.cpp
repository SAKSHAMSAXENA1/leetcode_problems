class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // largest subarray with at most 2 diff elements
        unordered_map<int,int> u;
        int l=0,r=0,n=fruits.size(),maxLen=0;

        while(r<n)
        {
            u[fruits[r]]++; // (acquire)

            while(u.size()>2) //while the subarray has more than two distinct types of elements
            {
                u[fruits[l]]--; // (release)
                if(u[fruits[l]]==0) u.erase(fruits[l]); // (release)      
                l++; // shrink
            }

            // now the subarray has <=2 distinct types of elements, so update maxLen
            maxLen=max(maxLen,r-l+1);
            r++; // expand
        }
        return maxLen;
    }
};