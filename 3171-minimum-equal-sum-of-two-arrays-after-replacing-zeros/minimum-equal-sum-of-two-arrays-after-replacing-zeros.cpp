#define ll long long
class Solution {
public:
ll f(ll &s1,ll &c1,ll &s2,ll &c2)
{
    if(c2==0) return -1;

    if(c1==0 && s1<s2+c2) return -1;

    if(c1!=0) return max(s1+c1,s2+c2);

    // else if(c1==0 && s1>=s2+c2)
    return s1;
}
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1=0,s2=0,c1=0,c2=0;

        for(auto it:nums1)
        {
            if(it>0) s1+=it;
            else c1++;
        }

        for(auto it:nums2)
        {
            if(it>0) s2+=it;
            else c2++;
        }

        if(s1==s2)
        {
            if(c1!=0 && c2!=0) return s1+max(c1,c2);
            else if(c1==0 && c2==0) return s1;
            else // only one of c1 & c2 is zero
            return -1; 
        }
        else if(s1>s2)
        return f(s1,c1,s2,c2);
        // else if(s2>s1) 
        return f(s2,c2,s1,c1);
    }
};