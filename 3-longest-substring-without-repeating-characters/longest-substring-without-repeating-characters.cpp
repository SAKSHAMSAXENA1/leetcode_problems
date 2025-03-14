class Solution {
public:
bool containsDuplicate(unordered_map<char,int> &u)
{
    for(auto it:u)
    {
        if(it.second>1) return true;
    }

    return false;
}
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),r=0,l=0,maxLen=0;
        unordered_map<char,int> u;

        while(r<n)
        {
            u[s[r]]++;

            while(containsDuplicate(u)) // while window contains duplicate char
            {
                u[s[l]]--;
                if(u[s[l]]==0) u.erase(s[l]);
                l++; // shrink the window (release)
            }

            // now window does not contain any duplicate char, so update the maxLen
            maxLen=max(maxLen,r-l+1);
            r++; // expand the window (acquire)
        }

        return maxLen;
    }
};