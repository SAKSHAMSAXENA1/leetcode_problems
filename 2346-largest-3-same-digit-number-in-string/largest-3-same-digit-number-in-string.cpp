class Solution {
public:
    string largestGoodInteger(string num) {
        string maxi="";
        int n=num.size();

        for(int i=0;i<=n-3;i++)
        {
            if(num[i]==num[i+1] && num[i+1]==num[i+2])
            {
                string curSubstring=num.substr(i,3);
                if(maxi.size()==0 || curSubstring > maxi)
                maxi=curSubstring;
            }
        }

        return maxi;
    }
};