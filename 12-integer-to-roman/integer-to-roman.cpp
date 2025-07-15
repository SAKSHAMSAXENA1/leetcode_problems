class Solution {
public:
    string intToRoman(int num) {
        string res="";

        float placeVal=0.1;

        while(num)
        {
            int dig=num%10;
            bool digGTE5=false;
            placeVal*=10;
            num/=10;

            if(dig==4)
            {
                if(placeVal==1) res="IV"+res; // 4
                else if(placeVal==10) res="XL"+res; // 40
                else if(placeVal==100) res="CD"+res; // 400
                continue;
            }
            else if(dig==9)
            {
                if(placeVal==1) res="IX"+res; // 9
                else if(placeVal==10) res="XC"+res; // 90
                else if(placeVal==100) res="CM"+res; // 900
                continue;
            }
            else if(dig>=5)
            {
                digGTE5=true;
                dig-=5;
            }

            while(dig--)
            {
                if(placeVal==1) res="I"+res; // 1
                else if(placeVal==10) res="X"+res; // 10
                else if(placeVal==100) res="C"+res; // 100
                else res="M"+res; // 1000
            }

            if(digGTE5)
            {
                if(placeVal==1) res="V"+res; // 5
                else if(placeVal==10) res="L"+res; // 50
                else if(placeVal==100) res="D"+res; // 500
            }
        }

        return res;
    }
};