#define ll long long
class Solution {
public:
int findCntSetBits(ll num)
{
    int cnt=0;

    while(num)
    {
        cnt+=num%2;
        num/=2;
    }

    return cnt;
}
    int makeTheIntegerZero(int num1, int num2) {
        int t=1;
        while(true)
        {
            ll val=num1-(ll)t*num2;

            if(val <= 0) break;

            int cntSetBits=findCntSetBits(val);

            if(cntSetBits<=t && t<=val) return t;

            t++;
        }

        return -1;
    }
};