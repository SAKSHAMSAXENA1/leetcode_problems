class Solution {
public:
bool f(int power,int target)
{
    //int power=1;

    if(target==0) return true;
    
    if(target<power) return false;

    // take
    if(f(power*3,target-power)==true) return true;

    //notTake
    if(f(power*3,target)==true) return true;

    /*while(power<=target)
    {
        used.insert(power);
        if(f(target-power,used)==true) return true;
        used.erase(power);
        power*=3;
    }*/

    return false;
}
    bool checkPowersOfThree(int n) {
        return f(1,n);
    }
};