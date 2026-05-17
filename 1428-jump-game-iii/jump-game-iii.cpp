class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n,false); 
        queue<int> q;
        q.push(start);
        vis[start] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            if(arr[node]==0) return true;

            int left = node - arr[node];

            if(0<=left && !vis[left])
            {
                q.push(left);
                vis[left] = true;
            }

            int right = node + arr[node];
            if(right<n && !vis[right])
            {
                q.push(right);
                vis[right] = true;
            }
        }

        return false;
    }
};