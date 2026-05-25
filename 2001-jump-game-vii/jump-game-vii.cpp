class Solution {
public:
int lb(vector<int> &vec,int key,int &m)
{
    int l = 0, h = m-1, res = m;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(key <= vec[mid])
        {
            res = mid;
            h=mid-1;
        }
        else // vec[mid] < key
        l=mid+1;
    }

    return res;
}

int ub(vector<int> &vec,int key,int &m)
{
    int l = 0, h = m-1, res = m;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(key < vec[mid])
        {
            res = mid;
            h=mid-1;
        }
        else // vec[mid] <= key
        l=mid+1;
    }

    return res;
}
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1') return false;

        int n = s.size(),prevFarthest = -1;

        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]  = true;

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            if(cur==n-1) return true;

            int l = max(cur+minJump,prevFarthest+1);
            int r = min(cur+maxJump,n-1);

            for(int j = l;j<=r;j++)
            {
                if(s[j]=='0' && !vis[j])
                {
                    q.push(j);
                    vis[j] = true;
                }
            }

            prevFarthest = r;
        }

        return false;
    }
};