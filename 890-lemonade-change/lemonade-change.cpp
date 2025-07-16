class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0,count10=0;

        for(auto it:bills)
        {
            if(it==5)
            {
                count5++;
                continue;
            }
            else if(it==10)
            {
                count10++;
                if(count5<1) return false;
                count5--; 
            }
            else // it==20
            {
                if(count10)
                {
                    count10--;
                    if(count5) count5--;
                    else return false;
                }
                else if(count5>=3)
                {
                    count5-=3;
                }
                else return false;
            }
        }

        return true;
    }
};