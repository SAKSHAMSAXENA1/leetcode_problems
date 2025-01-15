class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits1=0, setBits2=0;

        for(int i=31;i>=0;i--)
        {
            if((num1>>i)&1) setBits1++;
            if((num2>>i)&1) setBits2++;
        }

        if(setBits1==setBits2) return num1;

        int res;
        
        if(setBits1>setBits2)
        {
            res=num1;
            for(int i=31;i>=0 && setBits2;i--)
            {
                if((num1>>i)&1)
                {
                    res^=(1<<i);
                    setBits2--;
                }
            }

            return res^num1;
        }

        // else (setBits2>setBits1)
        int remBits2=setBits2-setBits1;
        res=0;

        for(int i=0;i<=31 && remBits2;i++)
        {
            if((num1>>i)&1) continue; // since we have to convert 0s to 1s

            res|=(1<<i);
            remBits2--;
        }

        return res^num1;
    }
};