class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        vector<bool> toRemove(n,true);
        stack<int> openParenthesis;
        string res="";

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                openParenthesis.push(i);
            }
            else if(s[i]==')')
            {
                if(!openParenthesis.empty())
                {
                    toRemove[openParenthesis.top()]=false;
                    openParenthesis.pop();
                    toRemove[i]=false;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(('a'<=s[i] && s[i]<='z') || toRemove[i]==false ) res.push_back(s[i]);
        }

        return res;
    }
};