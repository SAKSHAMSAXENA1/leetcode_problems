class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size(),res=0;
        vector<int> nge(n),pge(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            st.pop();

            nge[i] = (!st.empty()) ? st.top() : n;

            st.push(i); 
        }

        st=stack<int>();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
            st.pop();

            pge[i] = (!st.empty()) ? st.top() : -1;

            st.push(i);
        }

        for(int i=0;i<n;i++)
        if(left<=nums[i] && nums[i]<=right)
        res+=(i-pge[i])*(nge[i]-i);

        return res;
    }
};