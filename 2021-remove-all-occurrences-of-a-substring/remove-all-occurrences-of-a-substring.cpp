class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n=s.size(),m=part.size();

        for(int i=0;i<n;i++)
        {
            if(s[i]!=part[m-1] || st.size()<m-1) st.push(s[i]);
            else
            {
                int j=m-2;
                while(j>=0 && part[j]==st.top())
                {
                    st.pop();
                    j--;
                }

                if(j>=0)
                {
                    j++;
                    while(j<m)
                    {
                        st.push(part[j]);
                        j++;
                    }
                }
            }
        }

        string res="";
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};