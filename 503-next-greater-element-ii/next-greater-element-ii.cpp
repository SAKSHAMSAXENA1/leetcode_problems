class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=0;i<n-1;i++)
        {
            nums.push_back(nums[i]);
            st.push(nums[n-2-i]);
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
            {
                st.pop();
            }

            if(st.empty()) res[i]=-1;
            else res[i]=st.top();

            st.push(nums[i]);
        }

        return res;
    }
};