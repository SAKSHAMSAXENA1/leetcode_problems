class Solution {
public:
int findPoints(string &s,string &str,int &x)
{
    string temp="";
    int points=0;
    for(auto it:s)
    {
        if(it==str[1] && !temp.empty() && temp.back()==str[0])
        {
            temp.pop_back();
            points+=x;
        }
        else temp.push_back(it);
    }

    s=temp;
    return points;
}
    int maximumGain(string s, int x, int y) {
        string maxStr="ab",minStr="ba"; // assumption: x>y

        if(y>x)
        {
            swap(maxStr,minStr);
            swap(x,y);
        }

        return findPoints(s,maxStr,x)+findPoints(s,minStr,y);
    }
};