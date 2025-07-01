class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size(),res=0;

        for(int i=0;i<n;i++)
        {
            int j=i+1;

            while(j<n && word[j]==word[i])
            j++;

            res+=j-i-1;
            i=j-1;
        }

        res=res+1; // +1 for the case of 0 zero long presses
        return res;
    }
};