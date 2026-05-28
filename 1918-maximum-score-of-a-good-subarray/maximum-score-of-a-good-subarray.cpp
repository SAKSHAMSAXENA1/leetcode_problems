class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size(),res=INT_MIN;
        stack<int> st;
        vector<int> nse(n),pse(n);

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

            pse[i]=(st.empty()) ? -1 : st.top();

            st.push(i);
        }

        st=stack<int>();

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

            nse[i]=(st.empty()) ? n : st.top();

            st.push(i);
        }

        for(int i =0;i<n;i++)
        {
            if(pse[i]<k && k<nse[i])
            res=max(res,nums[i]*(nse[i]-1-pse[i]));
        }

        return res;
    }
};