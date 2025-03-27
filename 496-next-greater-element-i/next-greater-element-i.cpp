class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> u;
        int n2=nums2.size(),n1=nums1.size();
        vector<int> res(n1);
        stack<int> st;

        for(int j=n2-1;j>=0;j--)
        {
            while(!st.empty() && st.top()<nums2[j])
            {
                st.pop();
            }

            if(!st.empty()) u[nums2[j]]=st.top();
            else u[nums2[j]]=-1;

            st.push(nums2[j]);
        }

        for(int i=0;i<n1;i++)
        {
            res[i]=u[nums1[i]];
        }

        return res;
    }
};