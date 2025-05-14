class Solution {
public:
void f(int index,string &ds,bool lastBit,int &n,vector<string> &res)
{
    if(index==n)
    {
        res.push_back(ds);
        return;
    }

    ds.push_back('1'); // you can always put a '1'
    f(index+1,ds,true,n,res);
    ds.pop_back();

    if(lastBit==true) // but you can place a '0' only if lastBit was '1'
    {
        ds.push_back('0');
        f(index+1,ds,false,n,res);
        ds.pop_back();
    }
}
    vector<string> validStrings(int n) {
        vector<string> res;
        string ds="";
        f(0,ds,true,n,res);
        return res;
    }
};