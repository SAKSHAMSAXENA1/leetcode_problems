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
        int n=derived.size(),prev,orig0;

        // checking if original[0]=1 is a valid answer
        prev=1,orig0=1;
        for(int i=1;i<=n;i++)
        {
            int req=prev^derived[i-1];

            if(i==n && req==orig0) return true;

            prev=req;
        }

        // checking if original[0]=0 is a valid answer
        prev=0,orig0=0;
        for(int i=1;i<=n;i++)
        {
            int req=prev^derived[i-1];

            if(i==n && req==orig0) return true;

            prev=req;
        }

        return false;
    }
};