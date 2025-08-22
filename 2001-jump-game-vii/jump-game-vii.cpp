class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size(),largestJ=-1;
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;

        while(!q.empty())
        {
            int cur=q.front();
            q.pop();

            if(cur==n-1) return true;

            int start;
            if(largestJ==-1)
                start=cur+minJump;
            else
                start=max(cur+minJump,largestJ+1);

            int end=min(cur+maxJump,n-1);
            for(int j=start;j<=end;j++)
            {
                if(s[j]=='0' && !vis[j])
                {
                    q.push(j);
                    vis[j]=true;
                }
            }

            largestJ=max(largestJ,end);
        }

        return false;
    }
};