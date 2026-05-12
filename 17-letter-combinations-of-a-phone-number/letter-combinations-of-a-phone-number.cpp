class Solution {
public:
void f(int i,string ds,unordered_map<char,vector<char>> &u,string &digits,int &n,vector<string> &res)
{
    if(i==n) 
    {
        res.push_back(ds);
        return;
    }

    for(auto &c: u[digits[i]])
    {
        ds.push_back(c);

        f(i+1,ds,u,digits,n,res);

        ds.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<char,vector<char>> u;
        int n=digits.size();
        u['2']={'a','b','c'};
        u['3']={'d','e','f'};
        u['4']={'g','h','i'};
        u['5']={'j','k','l'};
        u['6']={'m','n','o'};
        u['7']={'p','q','r','s'};
        u['8']={'t','u','v'};
        u['9']={'w','x','y','z'};

        f(0,"",u,digits,n,res);

        return res;

    }
};