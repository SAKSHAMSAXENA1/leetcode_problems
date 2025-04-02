class Solution {
public:
    string removeKdigits(string num, int k) {
        // string also works like stack, so use it directly without using temporary stack
        // res is monotonic increasing, similar to monotonic increasing stack
        string res="";  
         

        for(auto it:num)
        {
            // while res already has higher digits and i have freedom to delete digits,
            // keep popping them from res
            while(res.size() && res.back()>it && k>0)
            {
                res.pop_back();
                k--;
            }

            // if res is non-empty, then push the current digit without any concern,
            // otherwise if res is empty then push the current digit only if it is non-zero
            // to avoid the issue of leading/preceding zeros
            if(res.size() || it!='0')
            res.push_back(it);
        }

        // while i still have freedom to delete char, remove the ones at the back/last
        // since res is monotonic increasing, the later digits are of higher val than prev digits
        while(res.size() && k>0)
        {
            res.pop_back();
            k--;
        }

        if(res=="") return "0";
        return res;

    }
};