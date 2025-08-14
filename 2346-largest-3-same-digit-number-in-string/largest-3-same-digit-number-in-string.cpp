class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_set<string> st;
        string maxi="";
        int n=num.size();

        for(char c='0';c<='9';c++)
        {
            string temp="";
            temp.append(3,c);
            st.insert(temp);
        }

        for(int i=0;i<=n-3;i++)
        {
            string curSubstring=num.substr(i,3);

            if(st.find(curSubstring)!=st.end() && (maxi.size()==0 || curSubstring > maxi))
            maxi=curSubstring;
        }

        return maxi;
    }
};