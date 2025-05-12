class Solution {
public:
void f(int len,int num,vector<bool> &vis,vector<int> &digits,int &n,set<int> &res)
{
    if(len==3)
    {
        res.insert(num);
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(vis[i] || (len==0 && digits[i]==0) || (len==2 && digits[i]%2==1))
        continue;
        
        vis[i]=true;
        num=num*10+digits[i];
        f(len+1,num,vis,digits,n,res);
        vis[i]=false;
        num/=10;
    }
}
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<bool> vis(n,false);
        set<int> res;
        f(0,0,vis,digits,n,res);
        vector<int> result(res.begin(),res.end());
        return result;
    }
};