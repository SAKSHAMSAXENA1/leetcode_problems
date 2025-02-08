class Solution {
public:
bool isNeighbour(string &a,string &b)
{
    int m=a.size();
    if(m!=b.size()) return false;
    int cntMismatch=0;
    for(int i=0;i<m;i++)
    {
        if(a[i]!=b[i]) cntMismatch++;

        if(cntMismatch>1) return false;
    }

    return true;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag=false;
        for(auto it:wordList)
        {
            if(it==endWord) 
            {
                flag=true;
                break;
            }
        }
        if(flag==false) return 0;

        bool shouldInsert=true;
        int src=0,n=wordList.size();
        for(int i=0;i<n;i++)
        {
            if(wordList[i]==beginWord) 
            {
                shouldInsert=false;
                src=i;
                break;
            }
        }
        if(shouldInsert) 
        {
            wordList.insert(wordList.begin(),beginWord);
            n++;
        }

        vector<vector<int>> adj(n, vector<int>());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //if(i==j) continue;

                if(isNeighbour(wordList[i], wordList[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> dist(n , 1e9);
        dist[src]=0;
        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();

            for(auto neighbour: adj[curNode])
            {
                if(dist[curNode]+1<dist[neighbour])
                {
                    dist[neighbour]=dist[curNode]+1;
                    q.push(neighbour);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(wordList[i]==endWord && dist[i]!=1e9)
            {
                res=dist[i]+1;
                break;
            }
        }

        return res;
    }
};