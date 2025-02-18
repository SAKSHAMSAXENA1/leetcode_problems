class Solution {
public:
bool f(int i,string &ds,string &pattern,vector<bool> &used,int &n)
{
    if(i==n) return true;

    char start='1',end='9';
    if(i>=0)
    {
        if(pattern[i]=='D') end=ds.back()-1;
        else start=ds.back()+1;
    }
    for(char c=start;c<=end;c++)
    {
            if(used[c-'1']) continue;

            ds.push_back(c);
            used[c-'1']=true;
            if(f(i+1,ds,pattern,used,n)==true) return true;
            ds.pop_back();
            used[c-'1']=false;
    }

    return false;
}
    string smallestNumber(string pattern) {
        int n=pattern.size();
        vector<bool> used(9, false);
        string ds="";
        f(-1,ds,pattern,used,n);
        return ds;
    }
};