class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector<pair<int,int>> vec;
        int n=arr.size(), res = 1;

        for(int i=0;i<n;i++)
        vec.push_back({i,arr[i]});

        auto comp=[&](pair<int,int> &a,pair<int,int> &b){
            if(a.second == b.second) // same height lower index first
            return a.first < b.first;

            return a.second < b.second; // lower height first
        };

        sort(vec.begin(),vec.end(),comp);

        vector<int> dp(n,1),pse(n),nse(n);
        stack<int> st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();

            pse[i] = st.empty() ? 0 : st.top() + 1;

            st.push(i);
        }

        st=stack<int>();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();

            nse[i] = st.empty() ? n-1 : st.top() - 1;

            st.push(i);
        }

        for(auto &[idx,ht] : vec)
        {
            int l = max(idx-d,pse[idx]), r = min(idx+d,nse[idx]);

            for(int j=l;j<idx;j++)
            dp[idx] = max(dp[idx], dp[j]+1);

            for(int j=idx+1;j<=r;j++)
            dp[idx]=max(dp[idx],dp[j]+1);

            res = max(res,dp[idx]);
        }

        return res;
    }
};