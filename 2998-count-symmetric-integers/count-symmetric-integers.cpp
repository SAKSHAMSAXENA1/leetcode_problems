class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++)
        {
            int temp=i,totSum=0,dig=0;
            while(temp)
            {
                totSum+=temp%10;
                dig++;
                temp/=10;
            }

            if(dig%2) continue;

            int halfDig=dig/2,halfSum=0;
            temp=i;
            for(int j=0;j<halfDig;j++)
            {
                halfSum+=temp%10;
                temp/=10;
            }

            if(2*halfSum==totSum) cnt++;
        }
        
        return cnt;
    }
};