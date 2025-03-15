class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3]={-1,-1,-1}; // initially last seen index of each character is -1,
        // indicating that it is not seen yet
        int cnt=0,n=s.size();

        for(int i=0;i<n;i++)
        {
            lastSeen[s[i]-'a']=i;

            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1) 
            {
                cnt+=1+min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
            }
        }

        return cnt;
    }
};