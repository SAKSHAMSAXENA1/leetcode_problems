class Solution {
public:
    string intToRoman(int num) {
        //unordered_map<int,string> u;
        //u[1]="I";u[5]="V";u[10]="X";u[50]="L";u[100]="C";u[500]="D";u[1000]="M";
        string res="";

        int placeVal=1;

        while(num)
        {
            int dig=num%10;
            //int val=dig*placeVal;
            bool digGTE5=false;
            num/=10;

            if(dig==4)
            {
                if(placeVal==1) res="IV"+res;
                else if(placeVal==10) res="XL"+res;
                else if(placeVal==100) res="CD"+res;

                placeVal*=10;
                continue;
            }
            else if(dig==9)
            {
                if(placeVal==1) res="IX"+res;
                else if(placeVal==10) res="XC"+res;
                else if(placeVal==100) res="CM"+res;

                placeVal*=10;
                continue;
            }
            else if(dig>=5)
            {
                digGTE5=true;
                dig-=5;
            }

            while(dig--)
            {
                if(placeVal==1) res="I"+res;
                else if(placeVal==10) res="X"+res;
                else if(placeVal==100) res="C"+res;
                else res="M"+res;
            }

            if(digGTE5)
            {
                if(placeVal==1) res="V"+res;
                else if(placeVal==10) res="L"+res;
                else if(placeVal==100) res="D"+res;
            }

            placeVal*=10;
        }

        return res;
    }
};