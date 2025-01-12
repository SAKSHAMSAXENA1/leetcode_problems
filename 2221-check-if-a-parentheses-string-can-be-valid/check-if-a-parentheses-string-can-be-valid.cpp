class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> openingBr, unlocked;
        int n=s.size();
        if(n%2) return false;

        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0') unlocked.push(i);
            else if(s[i]=='(') openingBr.push(i);
            else // s[i]==')'
            {
                if(!openingBr.empty()) openingBr.pop();
                else if(!unlocked.empty()) unlocked.pop();
                else return false;
            }
        }

        while(!openingBr.empty() && !unlocked.empty() && openingBr.top()<unlocked.top())
        {
            openingBr.pop();
            unlocked.pop();
        }

        return openingBr.empty();
    }
};