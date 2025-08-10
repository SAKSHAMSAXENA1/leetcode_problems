class Solution {
public:
void findFreq(int n,int freq[])
{
    while(n)
    {
        freq[n%10]++;
        n/=10;
    }
}
    bool reorderedPowerOf2(int n) {
        int freq[10]={0};
        findFreq(n,freq);

        for(int i=1;i<=(1e9);i*=2)
        {
            int freqI[10]={0};

            findFreq(i,freqI);

            bool ansFound=true;

            for(int k=0;k<10;k++)
            {
                if(freqI[k]!=freq[k])
                {
                    ansFound=false;
                    break;
                }
            }

            if(ansFound==true) return true;
        }

        return false;
    }
};