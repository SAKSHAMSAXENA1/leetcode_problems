class Solution {
public:
    string removeKdigits(string num, int k) {
        // stack is monotonic increasing-> last digits will be higher than prev digits
        stack<char> st;
        string res="";

        for(auto it:num)
        {
            // while the stack has higher digits in it and you have the freedom to delete
            //, pop out digits/char from stack 
            while(!st.empty() && st.top()>it && k>0)
            {
                st.pop(); // remove higher digits from stack
                k--; // decrease the freedom to delete char
            }

            // if the stack already has some elements, then push 'it' without any concern
            // otherwise, if the stack is empty, then push only non-zero digits into it
            // to avoid issue of leading/preceding zeros
            if(st.size() || it!='0')
            st.push(it);  
        }

        // while you still have freedom to delete digits, pop out the last digits
        // since stack is montonic increasing, the later digits will be higher than prev digits
        while(st.size() && k>0) 
        {
            st.pop();
            k--;
        }

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());
        if(res=="") return "0";
        return res;


    }
};