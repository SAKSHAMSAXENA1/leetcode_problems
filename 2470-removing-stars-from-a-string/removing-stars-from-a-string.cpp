class Solution {
public:
    string removeStars(string s) {
        string st; // string also functions like stack -> pop_back=pop,push_back=push

        for(auto it:s)
        {
            if(it=='*') st.pop_back();
            else st.push_back(it);
        }

        return st;
    }
};