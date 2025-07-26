class Solution {
public:
int findPoints(string &s,string &str,int &x)
{
    int i=0; // writing pointer, all char before 'i' represent my ans after pattern 'str'
    // has been removed from 's'
    // hence char from 'i' onwards are the ones that are to be deleted to get the 'ans'
    // after performing equivalent stack operations

    int n=s.size(),points=0;
    for(int j=0;j<n;j++) // j is the reading pointer
    {
        s[i]=s[j]; // char read by 'j' is written at 'i' in 's'
        i++;

        if(i>=2 && s[i-2]==str[0] && s[i-1]==str[1]) // pattern str is found in s
        {
            points+=x;
            i-=2;
            // char s[i-2] && s[i-1] are to be deleted, hence overwriting them will not 
            // make any difference (safe to overwrite them)
        }
    }

    s.erase(s.begin()+i,s.end());
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