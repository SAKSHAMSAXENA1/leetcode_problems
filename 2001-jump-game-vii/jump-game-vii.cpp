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

        int n = s.size(),m=0,prevFarthest = -1;
        vector<int> zeros;

        for(int i =0;i<n;i++)
        {
            if(s[i]=='0')
            {
                zeros.push_back(i);
                m++;
            }
        }

        /*for(int i=0;i<m;i++)
        cout<<i<<" ";

        cout<<endl;

        for(auto &i:zeros)
        cout<<i<<" ";

        cout<<endl;*/

        vector<bool> vis(m,false);
        queue<int> q;
        q.push(0);
        vis[0]  = true;

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            if(cur==n-1) return true;

            int l = max(lb(zeros,cur+minJump,m),prevFarthest+1);
            int r = ub(zeros,cur+maxJump,m) - 1;

           // cout<<cur<<" : "<<l<<" to "<<r<<" -> ";

            for(int j = l;j<=r;j++)
            {
                if(!vis[j])
                {
                    q.push(zeros[j]);
                    vis[j] = true;
                }
            }

            prevFarthest = r;

           // cout<<endl;
        }

        return false;
    }
};