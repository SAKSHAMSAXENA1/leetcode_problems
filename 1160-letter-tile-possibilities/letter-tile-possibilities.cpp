class Solution {
public:
void f(string &ds,string &tiles,vector<bool> &used,int &n,unordered_set<string> &res)
{   
    if(ds.size()) res.insert(ds);
    for(int i=0;i<n;i++)
    {
        //take
        if(!used[i])
        {
            used[i]=true;
            ds.push_back(tiles[i]);
            f(ds,tiles,used,n,res);
            used[i]=false;
            ds.pop_back();
        }
    }
}
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        vector<bool> used(n,false);
        unordered_set<string> res;
        string ds="";
        f(ds,tiles,used,n,res);;
        return res.size();
    }
};