class Solution {
public:
bool f(string &s,int index,int target,int &noOfDigits)
{
    if(index==noOfDigits) return target==0;
    int sum=0;
    for(int i=index;i<noOfDigits;i++)
    {
        sum=sum*10+(s[i]-'0');
        if(sum>target) break;
        if(f(s,i+1,target-sum,noOfDigits)==true) return true;
    }
    return false;
}
    int punishmentNumber(int n) {
        int res=0;
        for(int i=1;i<=n;i++)
        {
            string square=to_string(i*i);
            int noOfDigits=square.size();
            if(f(square,0,i,noOfDigits)==true) res+=i*i;
        }

        return res;
    }
};