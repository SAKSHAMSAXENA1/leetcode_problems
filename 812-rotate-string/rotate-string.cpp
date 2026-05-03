class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(n!=goal.size()) return false;

        for(int i=0;i<n;i++)
        {
            int j=i,k=0;

            while(k<n)
            {
                if(s[j]!=goal[k]) break;

                j=(j+1)%n;
                k++;
            }

            if(k==n) return true;
        }

        return false;
    }
};