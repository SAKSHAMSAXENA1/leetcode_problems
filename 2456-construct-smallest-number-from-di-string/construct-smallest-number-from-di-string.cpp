class Solution {
public:
bool f(int i,string &ds,string &pattern,vector<bool> &used,int &n)
{
    if(i==n) return true;
    for(char c='1';c<='9';c++)
    {
        
        if(i==-1 || (pattern[i]=='D' && ds.back()>c) || (pattern[i]=='I' && ds.back()<c))
        {
            if(used[c-'1']) continue;

            ds.push_back(c);
            used[c-'1']=true;
            if(f(i+1,ds,pattern,used,n)==true) return true;
            ds.pop_back();
            used[c-'1']=false;
        }
        /*else
        {
            if((pattern[i]=='D' && ds.back()<=c) || (pattern[i]=='I' && ds.back()>=c))
            continue;

            ds.push_back(c);
            if(f(i+1,ds,pattern,n)==true) return true;
            ds.pop_back(); 
        }*/
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