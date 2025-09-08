class Solution {
public:
bool hasZero(int num)
{
    while(num)
    {
        if(num%10 == 0) return true;

        num/=10;
    }

    return false;
}
    vector<int> getNoZeroIntegers(int n) {
        int a=n/2,b=n-a;

        while(hasZero(a) || hasZero(b))
        {
            a++;b--;
        }

        return {a,b};
    }
};