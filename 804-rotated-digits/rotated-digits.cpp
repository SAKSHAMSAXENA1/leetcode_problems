class Solution {
public:
bool check(int n)
{
    bool canBeGood = false;

    while(n)
    {
        int dig=n%10;

        if(dig==3 || dig==4 || dig==7) return false;
        else if(dig==2 || dig==5 || dig==6 || dig==9)
        canBeGood = true;

        n/=10; 
    }

    return canBeGood;
}
    int rotatedDigits(int n) {
        int res=0;

        for(int i=1;i<=n;i++)
        {
            res+=check(i);
        }

        return res;
    }
};