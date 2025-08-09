class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;

        int cntSetBits=0;

        while(n)
        {
            cntSetBits+=n%2;
            n/=2;
        }

        return cntSetBits==1;
    }
};