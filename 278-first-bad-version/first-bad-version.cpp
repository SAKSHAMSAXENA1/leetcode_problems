// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,h=n,res=-1;

        while(l<=h)
        {
            int mid=((long)l+h)/2;

            if(isBadVersion(mid))
            {
                res=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return res;
    }
};