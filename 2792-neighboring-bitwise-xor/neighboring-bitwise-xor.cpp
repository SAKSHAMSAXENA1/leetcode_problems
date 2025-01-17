class Solution {
public:
bool f(int index, int prev, vector<int> &der,int orig0)
{
    if(index==0) //prev=2
    {
        bool one=f(index+1,1,der,1);

        if(one) return true;

        bool zero=f(index+1,0,der,0);

        return zero;
    }

    int req=prev^der[index-1];

    if(index==der.size()) return req==orig0;

    return f(index+1,req,der,orig0);
}
    bool doesValidArrayExist(vector<int>& derived) {
        return f(0,2,derived,2);
    }
};