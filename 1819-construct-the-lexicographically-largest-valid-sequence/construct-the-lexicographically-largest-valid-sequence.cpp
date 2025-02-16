class Solution {
public:
bool f(int index,int &resSize,vector<bool> &used,vector<int> &res,int &n)
{
    if(index==resSize) return true;
    if(res[index]!=0) return f(index+1,resSize,used,res,n);
    for(int digit=n;digit>=1;digit--)
    {
        int nextOccurrence=(digit==1)?index:index+digit;
        if(!used[digit] && nextOccurrence<resSize && res[nextOccurrence]==0)
        {
            used[digit]=true;
            res[index]=res[nextOccurrence]=digit;
            if(f(index+1,resSize,used,res,n)==true) return true;

            // backtracking
            used[digit]=false;
            res[index]=res[nextOccurrence]=0;
        }
    }

    return false;
}
    vector<int> constructDistancedSequence(int n) {
        int resSize=2*n-1;
        vector<int> res(resSize,0);
        vector<bool> used(n+1,false);
        f(0,resSize,used,res,n);
        return res;
        
    }
};