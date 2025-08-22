class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size(),largestJ=0;
        queue<int> q;
        q.push(0);

        while(!q.empty())
        {
            int cur=q.front();
            q.pop();

            if(cur==n-1) return true;

            int start=max(cur+minJump,largestJ+1);

            int end=min(cur+maxJump,n-1);
            for(int j=start;j<=end;j++)
            {
                if(s[j]=='0')
                {
                    q.push(j);
                }
            }

            largestJ=max(largestJ,end);
        }

        return false;
    }
};