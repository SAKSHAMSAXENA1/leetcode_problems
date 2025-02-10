class Solution {
public:
    string clearDigits(string s) {
        string res="";
        stack<int> st;
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if('a'<=s[i] && s[i]<='z') st.push(i);
            else if(!st.empty()) st.pop();
            else // current char is digit and stack is empty
            res.push_back(s[i]);
        }

        string temp="";
        while(!st.empty())
        {
            temp.push_back(s[st.top()]);
            st.pop();
        }

        reverse(temp.begin(),temp.end());
        res+=temp;
        return res;
    }
};